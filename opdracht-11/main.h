#define IRPIN 5
#define LEDPIN1 10
#define LEDPIN2 11
#define LEDPIN3 12
#define BYTESBUFFERSIZE 16

void checkLedNewStatus(int ledsToTurnOnOff[], int ledcount, byte knopcode[8]);
void finishMeasurement();
void addMeasurementBit(byte bit);
void printMeasurements();
void addMeasurement(timeunit period);

enum States {IDLE, MEASURING};

typedef unsigned short int timeunit;