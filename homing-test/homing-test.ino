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
#define stepsPerRevolution 16

#define emagPin 21

#define zCurrentPin 14

// Define initial switch states
int xSS = 0;
int ySS = 0;
int zSS = 0;
int ledPin = 13;

// Define xyz coordinates 
int xPos = 0;
int yPos = 0;
int zPos = 0;


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

  // Run the initial homing sequence to move the chalk handler to 0,0
  homingSequence();
}



// Sequence to move to 0,0 and set the motors home
void homingSequence() {
  // Home X
  while(!digitalRead(xSwitchPin)) {
    digitalWrite(xDirPin, HIGH);
    for (int i = 0; i < stepsPerRevolution; i++) {
      digitalWrite(xStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(xStepPin,LOW);
      delayMicroseconds(1000);
    }
  }  
  delayMicroseconds(5000);
  
  while(!digitalRead(ySwitchPin)) {
    digitalWrite(yDirPin, HIGH);
    for (int i = 0; i < stepsPerRevolution; i++) {
      digitalWrite(yStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(yStepPin,LOW);
      delayMicroseconds(1000);
    }
  }  
  delayMicroseconds(5000);
  
  while(!digitalRead(zSwitchPin)) {
    digitalWrite(zDirPin, HIGH);
    for (int i = 0; i < stepsPerRevolution; i++) {
      digitalWrite(zStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(zStepPin,LOW);
      delayMicroseconds(1000);
    }
  }  
  delayMicroseconds(5000);

  //Modify the global coordinates
  xPos = 0;
  yPos = 0;
  zPos = 0;
  
}

void loop() {
  // move to end of x travel
  while (xPos <= 2000) {
    digitalWrite(xDirPin, LOW);
    xPos += 1;
    digitalWrite(xStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(xStepPin,LOW);
    delayMicroseconds(1000);
  }
  delayMicroseconds(1000000); //wait 1 s
  //
  while (yPos <= 1500) {
    digitalWrite(yDirPin, LOW);
    yPos += 1;
    digitalWrite(yStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(yStepPin,LOW);
    delayMicroseconds(1000);
  }
  delayMicroseconds(1000000); //wait 1 s
  
  homingSequence();
}
