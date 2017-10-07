#include <Arduino.h>

#define IRPIN 5

typedef unsigned short int timeunit;

int lastIrStatus = LOW;

unsigned long startMeasurements = 0;
unsigned long lastRelativeMicros = 0;

timeunit* buffer = NULL;
int buffersize = 0;

void setup() {
    pinMode(IRPIN, INPUT);
    Serial.begin(9600);
    while (!Serial) { ; }
}

void addToBuffer(timeunit time) {
    if(buffer == NULL){
        buffer = (timeunit*) malloc(sizeof(timeunit));
        buffer[0] = time;
        buffersize = 1;
    }else{
        buffersize++;
        buffer = (timeunit*) realloc(buffer, sizeof(timeunit) * buffersize);
        buffer[buffersize-1] = time;
    }

    if(buffer == NULL)
        Serial.println("Allocation failed!");
}

void printoutBuffer(){
    bool high = false;
    for(int i = 0; i < buffersize; i++){
        Serial.println((high ? "Hi " : "Lo ") + String(buffer[i]));
        high = !high;
    }
    Serial.println("=======================");
}
void clearBuffer(){
    free(buffer);
    buffer = NULL;
    buffersize = 0;
}


void loop(){
    unsigned long now = micros();

    unsigned long relativeNow = now - startMeasurements;
    unsigned long relativePeriod = relativeNow - lastRelativeMicros;

    if(digitalRead(IRPIN) != lastIrStatus){
        lastIrStatus = lastIrStatus == HIGH ? LOW : HIGH;

        //start measuring if buffer is empty and new pulse is HIGH
        if(buffer == NULL && lastIrStatus == LOW) {
            startMeasurements = now;
            lastRelativeMicros = 0;
            return;
        }
        addToBuffer((timeunit) relativePeriod);
        lastRelativeMicros = relativeNow;
    }
    if((buffer != NULL && relativePeriod > 65530)){ //more than 65 ms nothing
        printoutBuffer();
        clearBuffer();
    }
}






