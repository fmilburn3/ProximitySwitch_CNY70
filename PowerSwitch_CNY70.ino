/*
  Demonstration of CNY70 Reflective Sensor being used as a proximity
  switch.  This simple circuit and sketch goes HIGH when a
  reflective surface is close and LOW when taken away.  The CNY70
  Reflective Sensor can be found at:
  https://www.addicore.com/Reflective-Optical-Sensor-CNY70-p/224.htm
  
  Note that "close" is very dependent on the surface.  The sensor
  as wired in this circuit could be used to detect if a drawer,
  lid, or door is open or not.  
  
  I found that quite a large resistor was needed to get good 
  readings (e.g. 100k ohm).
  
  The sketch was developed for the Texas Instruments MSP430F5529
  LaunchPad using Energia but should work with most LaunchPads.  It
  will also work on an Arduino Uno.  
  
  Circuit diagram
  --------------- 
                                
         3V3         GND
          |           |
        White       Green      Colors shown are arbitrary wire colors
          |           |        that can be used to keep things straight
        |-o----   ----o-|      
        |      ---      |      Looking down on CNY70 with
        |               |        - emitter LED on left
        |   O       O   |        - detector phototransistor on right
        |               |        - pins on bottom connect as shown
        |      ---      |        
        |-o----   ----o-|      Lettering is on right vertical face   
          |           |          with indents as shown
          |           |
          |           ------ Pin 6
          |           |
       Purple        Red       
          |           |
       100 ohm      100 k Ohm      
          |           |
         GND         3V3
         
  Arduino note: May use 5V instead of 3V3, this will increase the
  range significantly.
  
  Created by Frank Milburn, 25 June 2015
  Released into the public domain
*/

const int sensorPin = 7;         // Specify a digital pin
const int redPin = RED_LED;      // change to 13 for Arduino

void setup() 
{
  Serial.begin(9600);            // Initialize Serial        
  Serial.print("Starting proximity test...");
  pinMode(sensorPin, INPUT);     // Initialize pins
  pinMode(redPin, OUTPUT);
}

void loop() 
{
  int thisReading = digitalRead(sensorPin);   // Take a reading
  Serial.print("Reading: ");
  Serial.print(thisReading);
  if (thisReading == HIGH)                  
  {                                           
    Serial.println(": Reflective surface close");
    digitalWrite(redPin, HIGH);
  }  
  else
  {                                           
    Serial.println(": Reflective surface far");
    digitalWrite(redPin, LOW);
  } 
  delay(200);
}
