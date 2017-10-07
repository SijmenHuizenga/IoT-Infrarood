#include <Arduino.h>
#include "./circulairbuffer.cpp"

#define IRPIN 5

typedef unsigned short int timeunit;

int prevReading = LOW;

unsigned long startMeasurement = 0;
unsigned long lastMeasurement = 0;

CirculairBuffer<timeunit> buffer;

void setup() {
    //set IRPIN to input
    DDRD &= ~(1 << IRPIN);

    Serial.begin(9600);
    while (!Serial) { ; }
}

void printoutBuffer(){
    bool high = true;
    for(int i = 0; i < buffer.length(); i++){
        Serial.println((high ? "Lo " : "Hi ") + String(buffer.get(i)));
        high = !high;
    }
    Serial.println("=======================");
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

