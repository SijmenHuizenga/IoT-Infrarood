/**
 * Met deze code kun je de snelheid van serial.println berichten testen
 * wanneer de arduino niet verbonden is. Dit werkt als volgt:
 *
 * Upload de code op je arduino en disconnect de arduino van je computer.
 * Dan reconnect aan je computer. Belangrijk is om op dit moment geen serial
 * monitor te openen! Pas wanneer je op de arduino het gele 'TX' lampje om
 * de seconde ziet knipperen dan kun je de serial monitor openen.
 * In de serial monitor zie je resultaat.
 *
 * Het resultaat is het gemiddeld aantal microseconden van 1000 berichten
 * met een lengte van 60 karakters over de serial connectie met een 9600 baudrate.
 */

#include <Arduino.h>

#define LONGTEXT "aHR0cHM6Ly93d3cueW91dHViZS5jb20vd2F0Y2g/dj1kUXc0dzlXZ1hjUQ=="
#define AMOUNT 1000

void setup() {
    Serial.begin(9600);
}

unsigned long testSerialSpeed(int amount, String content){
    unsigned long start = micros();

    for(int i = 0; i < amount; i++)
        Serial.println(content);

    Serial.flush();

    return (micros() - start) / amount;
}

unsigned long println_long_b96 = 0;

void loop(){
    if(println_long_b96 == 0)
        println_long_b96 = testSerialSpeed(AMOUNT, LONGTEXT);

    Serial.println(println_long_b96);
    delay(1000);
}

