#include <Arduino.h>

#define IRPIN 5
#define LEDPIN 4

bool ledOn = false;
bool irOn = false;

void setup() {
    pinMode(IRPIN, INPUT);
    pinMode(LEDPIN, OUTPUT);
}

//wait for 99 ms if the ir pin is low. Returns true if low, else false.
bool isIrOn(){
    unsigned long start = millis();

    while((millis() - start) < 99){
        if(digitalRead(IRPIN) == LOW)
            return true;
    }
    return false;
}

void switchLed(){
    ledOn = !ledOn;
    digitalWrite(LEDPIN, ledOn ? 1 : 0);
}

void loop(){
    bool actualIrOn = isIrOn();
    if(!irOn && actualIrOn){
        irOn = true;
        switchLed();
    }else if(irOn && !actualIrOn){
        irOn = false;
    }
}













