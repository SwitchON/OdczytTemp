#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 12

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

//odstep miedzy pomiarami
unsigned int myDelay = 12;
int InputData = 0;
int i = 0;
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  
  // Start up the library
  sensors.begin();
}

void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  //Serial.println("Requesting temperatures...");
 if (i == 0){
   sensors.requestTemperatures(); // Send the command to get temperatures
  
  //Serial.println("Temperature for the device 1 (index 0) is: ");
  Serial.println(sensors.getTempCByIndex(0));
 }  
 
delay(5000);
i++;
if (i >= myDelay) i = 0;
}

unsigned int convertTodelay(int _inChar)
 { 
   unsigned int delayConverted = 12;
   switch (_inChar) {
    case 'a':
     delayConverted = 1;
     break;
    case 'b':
     delayConverted = 12;
     break;
    case 'c':
     delayConverted = 60;
     break;
    case 'd':
     delayConverted = 120;
     break;
    case 'e':
     delayConverted = 180;
     break;
    case 'f':
     delayConverted = 360; 
     break;
    case 'g':
     delayConverted = 720;      
     break;
    default: 
     delayConverted = 12;
  }
  return delayConverted;
 }
void serialEvent() {
   while (Serial.available()>0) {
     InputData = Serial.read();
      myDelay = convertTodelay(InputData);
   }
}
