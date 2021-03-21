#include <MultiStepper.h>

// Define limit switch pins
#define xSwitchPin 9
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

#define zCurrentPin 14

int ledPin = 13;

// Define xyz coordinates 
int xPos = 0;
int yPos = 0;
int zPos = 0;

int t = 1;

void setup() {
  // put your setup code here, to run once:
  
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);

  pinMode(zCurrentPin, INPUT);

  // Declare motors as output
  pinMode(xStepPin, OUTPUT);
  pinMode(xDirPin, OUTPUT);
  pinMode(yStepPin, OUTPUT);
  pinMode(yDirPin, OUTPUT); 
  pinMode(zStepPin, OUTPUT);
  pinMode(zDirPin, OUTPUT);

  pinMode(ledPin, OUTPUT);

  // Run the initial homing sequence to move the chalk handler to 0,0
  homingSequence();
}

void moveX(int xWant) {
  while (xPos != xWant) {
      if (xPos < xWant) {
        digitalWrite(xDirPin, LOW);
        xPos += 1;
        digitalWrite(xStepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(xStepPin,LOW);
        delayMicroseconds(1000);
      }
      else if (xPos > xWant) {
        digitalWrite(xDirPin, HIGH);
        xPos -= 1;
        digitalWrite(xStepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(xStepPin,LOW);
        delayMicroseconds(1000);
      }
   }
}

void moveY(int yWant) {
  while (yPos != yWant) {
      if (yPos < yWant) {
        digitalWrite(yDirPin, LOW);
        yPos += 1;
        digitalWrite(yStepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(yStepPin,LOW);
        delayMicroseconds(1000);
      }
      else if (yPos > yWant) {
        digitalWrite(yDirPin, HIGH);
        yPos -= 1;
        digitalWrite(yStepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(yStepPin,LOW);
        delayMicroseconds(1000);
      }
   }
}

void goSq(int x, int y){
  moveX(x);
  moveY(y);
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
  delayMicroseconds(500000);
  // put your main code here, to run repeatedly:
  goSq(1000, 850);
  while (zPos <= 212) {
    digitalWrite(zDirPin, LOW);
    zPos += 1;
    digitalWrite(zStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(zStepPin,LOW);
    delayMicroseconds(1000);
    Serial.print(zPos);
  }
  while(xPos < 2500) {
        digitalWrite(xDirPin, LOW);
        digitalWrite(yDirPin, LOW);
        xPos += 1;
        yPos += 1;
        digitalWrite(xStepPin, HIGH);
        digitalWrite(yStepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(xStepPin,LOW);
        digitalWrite(yStepPin,LOW);
        delayMicroseconds(1000);
  }
  moveX(500);
  while(xPos < 1000) {
        digitalWrite(xDirPin, LOW);
        digitalWrite(yDirPin, HIGH);
        xPos += 1;
        yPos -= 1;
        digitalWrite(xStepPin, HIGH);
        digitalWrite(yStepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(xStepPin,LOW);
        digitalWrite(yStepPin,LOW);
        delayMicroseconds(1000);
  }
  while (zPos > 2) {
    digitalWrite(zDirPin, HIGH);
    zPos -= 1;
    digitalWrite(zStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(zStepPin,LOW);
    delayMicroseconds(1000);
    Serial.print(zPos);
  }
  zPos = 0;
  homingSequence();
  delayMicroseconds(500000);
}
