#include <Arduino.h>
#include "./circulairbuffer.cpp"

#define IRPIN 5

typedef unsigned short int timeunit;

int prevReading = LOW;

unsigned long startMeasurements = 0;
unsigned long lastRelativeMicros = 0;

CirculairBuffer<timeunit> buffer;

void setup() {
    pinMode(IRPIN, INPUT);
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

    unsigned int relativeNow = static_cast<unsigned int>(now - startMeasurements);
    unsigned int relativePeriod = static_cast<unsigned int>(relativeNow - lastRelativeMicros);


    int reading = digitalRead(IRPIN);
    if(reading != prevReading){
        prevReading = reading;

        //start measuring if buffer is empty and new pulse is LOW
        if(buffer.empty() && reading == LOW) {
            startMeasurements = now;
            lastRelativeMicros = 0;
            return;
        }
        buffer.add((timeunit) relativePeriod);
        lastRelativeMicros = relativeNow;
    }
    //more than 65 ms nothing than done
    if(!buffer.empty() && relativePeriod > 65530){
        printoutBuffer();
        buffer.clear();
    }

}






