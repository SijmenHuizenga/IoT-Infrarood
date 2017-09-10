#include <Arduino.h>

#define IRPIN 5
#define LEDPIN 4

bool toggle;

void setup() {
    pinMode(IRPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
}

void loop(){
    if(digitalRead(IRPIN) == HIGH){
        toggle = !toggle;
        digitalWrite(LEDPIN, toggle ? 1 : 0);
        delay(1000);
    }
}