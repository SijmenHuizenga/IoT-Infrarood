#include <Arduino.h>
#include "./circulairbuffer.cpp"

#define IRPIN 2

typedef unsigned short int timeunit;

unsigned long startMeasurement = 0;
unsigned long lastMeasurement = 0;

CirculairBuffer<timeunit> buffer;

void setup() {
    pinMode(IRPIN, INPUT);
    Serial.begin(115200);
    while (!Serial) { ; }

    attachInterrupt(digitalPinToInterrupt(IRPIN), irChange, CHANGE);
}

void printoutBuffer(){
    bool high = true;
    for(int i = 0; i < buffer.length(); i++){
        Serial.println((high ? "Hi " : "Low ") + String(buffer.get(i)));
        high = !high;
    }
    Serial.println("=======================");
}
void loop(){
    //more than 65 ms nothing than done
    if(!buffer.empty() && (micros() - startMeasurement) > 65530){
        printoutBuffer();
        buffer.clear();
    }
}


void irChange(){
    unsigned long now = micros();

    if(buffer.empty()) {
        startMeasurement = now;
        lastMeasurement = startMeasurement;
    }

    buffer.add((timeunit) (now - lastMeasurement));
    lastMeasurement = now;
}







