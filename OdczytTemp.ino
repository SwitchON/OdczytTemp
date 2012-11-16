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
   switch (_inChar) {
    case 'a':
      return 1;
    case 'b':
     return 12;
    case 'c':
     return 60;
    case 'd':
     return 120;
    case 'e':
     return 180;
    case 'f':
     return 360; 
    case 'g':
     return 720;      
    default: 
      return 12;
  }
 }
void serialEvent() {
   while (Serial.available()>0) {
     InputData = Serial.read();
      myDelay = convertTodelay(InputData);
   }
}
