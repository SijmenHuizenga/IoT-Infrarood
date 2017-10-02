#include <Arduino.h>

//Hoe lang duurt een malloc?
void testA(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        unsigned long start = micros();
        int* data = (int*) malloc(10);
        total += micros() - start;
        free(data);
    }
    Serial.println("A: Gemiddelde tijd dat het kost om 50 bytes te alloceren over een gemiddelde van 1000 tests is " +
                           String(total/1000) + " microseconden.");
}

//Maakt het uit hoeveel geheugen je alloceert?
void testB(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        unsigned long start = micros();
        int* data = (int*) malloc(150);
        total += micros() - start;
        free(data);
    }
    Serial.println("B: Gemiddelde tijd dat het kost om 150 bytes te alloceren over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

//Hoe lang duurt een realloc?
void testC(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        int* data = (int*) malloc(1);
        unsigned long start = micros();
        data = (int*) realloc(data, 150);
        total += micros() - start;
        free(data);
    }
    Serial.println("C: Gemiddelde tijd dat het kost om 1 byte te reloccen naar 150 bytes "
                           "terwijl er verder niks speciaals is gealloceerd "
                           "over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

//Maakt het uit hoeveel geheugen er al gereserveerd was?
void testD(){
    unsigned long total = 0;
    int* extradata = (int*) malloc(150);
    for(int i = 0; i < 1000; i++){
        int* data = (int*) malloc(1);
        unsigned long start = micros();
        data = (int*) realloc(data, 150);
        total += micros() - start;
        free(data);
    }
    free(extradata);
    Serial.println("D: Gemiddelde tijd dat het kost om 1 byte te reloccen naar 150 bytes "
                           "terwijl er verder al 150 bytes gealloceerd zijn "
                           "over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

//Maakt het uit hoeveel geheugen je extra alloceert?
void testE(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        int* data = (int*) malloc(1);
        unsigned long start = micros();
        data = (int*) realloc(data, 50);
        total += micros() - start;
        free(data);
    }
    Serial.println("E: Gemiddelde tijd dat het kost om 1 byte te reloccen naar 50 bytes "
                           "terwijl er verder niks speciaals is gealloceerd "
                           "over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

//En is er verschil tussen het vergroten of juist verkleinen van de gealloceerde geheugenruimte?
void testF(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        int* data = (int*) malloc(150);
        unsigned long start = micros();
        data = (int*) realloc(data, 1);
        total += micros() - start;
        free(data);
    }
    Serial.println("F: Gemiddelde tijd dat het kost om 150 bytes te reloccen naar 1 byte "
                           "terwijl er verder niks speciaals is gealloceerd "
                           "over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

//In de slides werd gezegd dat calloc langer duurt dan malloc. Is dat eigenlijk wel waar?
void testG(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        unsigned long start = micros();
        int* data = (int*) calloc(10, 50);
        total += micros() - start;
        free(data);
    }
    Serial.println("G: Gemiddelde tijd dat het kost om 50 bytes te calloc-en over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

//Is “handmatig” initialiseren van de waarden na een malloc sneller of langzamer dan een calloc?
void testH(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        unsigned long start = micros();
        int* data = (int*) malloc(50);
        for(int j = 0; j < 50; j++)
            data[j] = 10;
        total += micros() - start;
        free(data);
    }
    Serial.println("H: Gemiddelde tijd dat het kost om 50 bytes te alloceren en daarna handmatige te initaliseren  "
                           "over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

//Maakt het voor een free uit hoeveel geheugen er gealloceerd was?
void testI(){
    unsigned long total = 0;
    for(int i = 0; i < 1000; i++){
        int* data = (int*) malloc(50);
        unsigned long start = micros();
        free(data);
        total += micros() - start;
    }
    Serial.println("I: Gemiddelde tijd dat het kost om 50 bytes te free-en over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");

    total = 0;
    for(int i = 0; i < 1000; i++){
        int* data = (int*) malloc(5);
        unsigned long start = micros();
        free(data);
        total += micros() - start;
    }
    Serial.println("I: Gemiddelde tijd dat het kost om 5 bytes te free-en over een gemiddelde van 1000 tests is " +
                   String(total/1000) + " microseconden.");
}

void setup() {
    Serial.begin(9600);
    while (!Serial) { ; }
    testA();
    delay(500);
    testB();
    delay(500);
    testC();
    delay(500);
    testD();
    delay(500);
    testE();
    delay(500);
    testF();
    delay(500);
    testG();
    delay(500);
    testH();
    delay(500);
    testI();
    delay(500);
}

void loop(){}
