#include <AccelStepper.h>
#include <MultiStepper.h>

// Define limit switch pins
#define xSwitchPin 8
#define ySwitchPin 10
#define zSwitchPin 11

// Define motor directions
#define xDirPin 2
#define xStepPin 3
#define yDirPin 4
#define yStepPin 5
#define zDirPin 6
#define zStepPin 7

// change this to change the step distance?
#define stepsPerRevolution 100

#define emagPin 21

#define zCurrentPin 14

// Define initial switch states
int xSS = 0;
int ySS = 0;
int zSS = 0;
int ledPin = 13;



void setup() {
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);

  pinMode(zCurrentPin, INPUT);

  // Declare motors and electromagnet as output
  pinMode(xStepPin, OUTPUT);
  pinMode(xDirPin, OUTPUT);
  pinMode(yStepPin, OUTPUT);
  pinMode(yDirPin, OUTPUT); 
  pinMode(zStepPin, OUTPUT);
  pinMode(zDirPin, OUTPUT); 
  pinMode(emagPin, OUTPUT);
 
  pinMode(ledPin, OUTPUT);
  homing-sequence();
}

// Capture all pin states
void pinStates() {
  xSS = digitalRead(xSP);
  ySS = digitalRead(ySP);
  zSS = digitalRead(zSP);
}

// Sequence to move to 0,0 and set the motors home
void homing-sequence() {
  //check if already homed
  pinStates();
  if (xSS == HIGH) {
    
  }
  
  
  
}

void loop() {

  delay(25); //wait 25 ms
}
