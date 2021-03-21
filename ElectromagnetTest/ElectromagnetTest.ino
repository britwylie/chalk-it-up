#include <MultiStepper.h>
/*Example, homes and draws a basic shape (e.g. circle)*/

// Define stepper motor connections and steps per revolution:
#define xDirPin 2
#define xStepPin 3
#define yDirPin 4
#define yStepPin 5
#define zDirPin 6
#define zStepPin 7
#define stepsPerRevolution 200

// Define limit switch pins
#define xSwitchPin 8
#define ySwitchPin 10
#define zSwitchPin 11

// Define current sensor
#define zCurrentPin 14

//Define electromagnet pin
#define emagPin 21

void setup() {
  // Declare motors and electomagnet as output:
  pinMode(xStepPin, OUTPUT);
  pinMode(xDirPin, OUTPUT);
  pinMode(yStepPin, OUTPUT);
  pinMode(yDirPin, OUTPUT); 
  pinMode(zStepPin, OUTPUT);
  pinMode(zDirPin, OUTPUT); 
  pinMode(emagPin, OUTPUT);
 
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);
  pinMode(zCurrentPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(xSwitchPin)) {
    digitalWrite(emagPin, HIGH);
  }
  else digitalWrite(emagPin, LOW);
  delayMicroseconds(100);
}
