#include <Arduino.h>

#define IRPIN 5

//aanname dat bij start van het programma geen ir licht wordt ontvangen
int oldStatus = HIGH;

unsigned long lastChange = 0;

void setup() {
    Serial.begin(9600);
    pinMode(IRPIN, INPUT);
}

void loop(){
    if(digitalRead(IRPIN) != oldStatus){

        Serial.println((String)(oldStatus ? "on" : "of") + " for " +  (micros() - lastChange) + " micros ");

        lastChange = micros();
        oldStatus = oldStatus == HIGH ? LOW: HIGH;
    }
}