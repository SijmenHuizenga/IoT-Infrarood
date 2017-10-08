#include <Arduino.h>
#include "main.h"
#include "ircodes.h"

int prevReading = LOW;

States state = IDLE;

unsigned long startMeasurementMoment = 0;
unsigned long lastMeasurementMoment = 0;

byte measurementNr = 0;
byte measurements[BYTESBUFFERSIZE];

void setup() {
    //set IRPIN to input
    DDRD &= ~(1 << IRPIN);
    pinMode(LEDPIN1, OUTPUT);
    pinMode(LEDPIN2, OUTPUT);
    pinMode(LEDPIN3, OUTPUT);

    Serial.begin(115200);
}

void loop(){
    unsigned long now = micros();

    int reading = (PIND >> IRPIN) & 1;
    if(reading != prevReading){
        prevReading = reading;

        //start measuring if buffer is empty and new pulse is LOW
        if(state == IDLE && reading == LOW) {
            state = MEASURING;
            startMeasurementMoment = now;
            lastMeasurementMoment = now;
            return;
        }
        addMeasurement((timeunit) (now-lastMeasurementMoment));
        lastMeasurementMoment = now;
    }
    //more than 65 ms nothing than done
    if(state != IDLE && (now-startMeasurementMoment) > 65530)
        finishMeasurement();
}

void addMeasurement(timeunit period) {
    //skip long start pulses.
    if(measurementNr == 0 && period > 4000)
        return;

    if(period >= 450 && period <= 650)
        addMeasurementBit(0);
    else if(period >= 1600 && period <= 1800)
        addMeasurementBit(1);
    else
        finishMeasurement();
}

void addMeasurementBit(byte bit) {
    bitWrite(measurements[measurementNr / 8], measurementNr % 8, bit);
    measurementNr++;
}

void finishMeasurement() {
    state = IDLE;
    if(measurementNr == 0)
        return;

    printMeasurements();

    checkLedNewStatus(new int[1]{LEDPIN1}, 1, KNOP1);
    checkLedNewStatus(new int[1]{LEDPIN2}, 1, KNOP2);
    checkLedNewStatus(new int[1]{LEDPIN3}, 1, KNOP3);
    checkLedNewStatus(new int[3]{LEDPIN1, LEDPIN2, LEDPIN3}, 3, KNOPONOFF);

    measurementNr = 0;
    for(int i = 0; i < BYTESBUFFERSIZE; i++)
        measurements[i] = 0;
}

void printMeasurements() {
    for (int i = 0; i < (measurementNr+7)/8; i++){
        for(int j = 7; j >= 0; j--)
            Serial.print(bitRead(measurements[i], j));
        Serial.println("    (" + String(measurements[i], DEC) + ")");
    }
    Serial.println();
}

void checkLedNewStatus(int *ledsToTurnOnOff, int ledcount, byte *knopcode) {
    for(int i = 0; i < 8; i++)
        if(measurements[i] != knopcode[i])
            return;
    bool newStatus = !digitalRead(ledsToTurnOnOff[0]);
    for(int i = 0; i < ledcount; i++)
        digitalWrite(ledsToTurnOnOff[i], newStatus);

}



