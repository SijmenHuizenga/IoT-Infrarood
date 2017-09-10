#include <Arduino.h>

#define LONGTEXT "aHR0cHM6Ly93d3cueW91dHViZS5jb20vd2F0Y2g/dj1kUXc0dzlXZ1hjUQ=="
#define SHORTTEXT "a"

void setup() {

}

unsigned long totalTimeStartingSerial = 0;

unsigned long testSerialSpeed(int amount, unsigned long baudrate, String content, bool usenewline){

    unsigned long startSerial = micros();
    Serial.begin(baudrate);
    totalTimeStartingSerial += micros() - startSerial;

    unsigned long start = micros();

    for(int i = 0; i < amount; i++){
        if(usenewline)
            Serial.println(content);
        else
            Serial.print(content);
    }

    Serial.flush();

    return (micros() - start) / amount;
}

void loop(){
    int amount = 1000;

    unsigned long println_short_b24 = testSerialSpeed(amount, 2400, SHORTTEXT, true);
    unsigned long println_long_b24 = testSerialSpeed(amount, 2400, LONGTEXT, true);
    unsigned long print_short_b24 = testSerialSpeed(amount, 2400, SHORTTEXT, false);
    unsigned long print_long_b24 = testSerialSpeed(amount, 2400, LONGTEXT, false);

    unsigned long println_short_b96 = testSerialSpeed(amount, 9600, SHORTTEXT, true);
    unsigned long println_long_b96 = testSerialSpeed(amount, 9600, LONGTEXT, true);
    unsigned long print_short_b96 = testSerialSpeed(amount, 9600, SHORTTEXT, false);
    unsigned long print_long_b96 = testSerialSpeed(amount, 9600, LONGTEXT, false);


    unsigned long println_short_b576 = testSerialSpeed(amount, 57600, SHORTTEXT, true);
    unsigned long println_long_b576 = testSerialSpeed(amount, 57600, LONGTEXT, true);
    unsigned long print_short_b576 = testSerialSpeed(amount, 57600, SHORTTEXT, false);
    unsigned long print_long_b576 = testSerialSpeed(amount, 57600, LONGTEXT, false);

    unsigned long println_short_b1152 = testSerialSpeed(amount, 115200, SHORTTEXT, true);
    unsigned long println_long_b1152 = testSerialSpeed(amount, 115200, LONGTEXT, true);
    unsigned long print_short_b1152 = testSerialSpeed(amount, 115200, SHORTTEXT, false);
    unsigned long print_long_b1152 = testSerialSpeed(amount, 115200, LONGTEXT, false);

    Serial.begin(9600);

    Serial.println("| method | textsize | baudrate | average over 100 calls in micros |");
    Serial.println("| ------ | -------- | -------- | ---------------------- |");
    Serial.println("| println | short | 2400   | " + String(println_short_b24) + " |");
    Serial.println("| println | short | 9600   | " + String(println_short_b96) + " |");
    Serial.println("| println | short | 57600  | " + String(println_short_b576) + " |");
    Serial.println("| println | short | 115200 | " + String(println_short_b1152) + " |");
    Serial.println("| println | long  | 2400   | " + String(println_long_b24) + " |");
    Serial.println("| println | long  | 9600   | " + String(println_long_b96) + " |");
    Serial.println("| println | long  | 57600  | " + String(println_long_b576) + " |");
    Serial.println("| println | long  | 115200 | " + String(println_long_b1152) + " |");
    Serial.println("| print   | short | 2400   | " + String(print_short_b24) + " |");
    Serial.println("| print   | short | 9600   | " + String(print_short_b96) + " |");
    Serial.println("| print   | short | 57600  | " + String(print_short_b576) + " |");
    Serial.println("| print   | short | 115200 | " + String(print_short_b1152) + " |");
    Serial.println("| print   | long  | 2400   | " + String(print_long_b24) + " |");
    Serial.println("| print   | long  | 9600   | " + String(print_long_b96) + " |");
    Serial.println("| print   | long  | 57600  | " + String(print_long_b576) + " |");
    Serial.println("| print   | long  | 115200 | " + String(print_long_b1152) + " |");
    Serial.println();

    Serial.println("Average time Serail.begin() over 16 runs is " + String(totalTimeStartingSerial) + " micros");

    delay(600000); //10 minuten
}

