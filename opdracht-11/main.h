#define IRPIN 5

#define LEDPIN1 10
#define LEDPIN2 11
#define LEDPIN3 12

#define BYTESBUFFERSIZE 16
#define BITSINBYTE 8

//the maximum time between the chaning of pulse in micros.
//If the time since last pulse is bigger than this nr than the measruement is finished.
#define MAXMEASUREMENTTIME 65530

//a pulse is a 'long' pulse if it is longer than LONGPULSE_BIGGER and smaller than LONGPULSE_SMALLER
#define LONGPULSE_SMALLER 650
#define LONGPULSE_BIGGER 450

//a pulse is a 'short' pulse if it is longer than SHORTPULSE_BIGGER and smaller than SHORTPULSE_SMALLER
#define SHORTPULSE_SMALLER 1800
#define SHORTPULSE_BIGGER 1600

void checkLedNewStatus(int ledsToTurnOnOff[], int ledcount, byte knopcode[8]);
void finishMeasurement();
void addMeasurementBit(byte bit);
void printMeasurements();
void addMeasurement(timeunit period);

enum States {IDLE, MEASURING};

typedef unsigned short int timeunit;