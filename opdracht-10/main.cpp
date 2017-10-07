#include <Arduino.h>
#include "./circulairbuffer.cpp"

#define IRPIN 5
#define LEDPIN 8

typedef unsigned short int timeunit;

int prevReading = LOW;

unsigned long startMeasurement = 0;
unsigned long lastMeasurement = 0;

CirculairBuffer<timeunit> buffer;

void setup() {
    //set IRPIN to input
    DDRD &= ~(1 << IRPIN);

    pinMode(LEDPIN, OUTPUT);
}

void printoutBuffer(){
    bool high = false;
    for(int i = 0; i < buffer.length(); i++){
        digitalWrite(LEDPIN, high ? HIGH : LOW);
        //received in microsecond, play in millisecond. So slowed down by 10.000x
        delay(static_cast<unsigned long>(buffer.get(i) / 10));
        high = !high;
    }
}

void loop(){
    unsigned long now = micros();

    int reading = (PIND >> IRPIN) & 1;
    if(reading != prevReading){
        prevReading = reading;

        //start measuring if buffer is empty and new pulse is LOW
        if(buffer.empty() && reading == LOW) {
            startMeasurement = now;
            lastMeasurement = now;
            return;
        }
        buffer.add((timeunit) (now-lastMeasurement));
        lastMeasurement = now;
    }
    //more than 65 ms nothing than done
    if(!buffer.empty() && (now-startMeasurement) > 65530){
        printoutBuffer();
        buffer.clear();
    }

}

