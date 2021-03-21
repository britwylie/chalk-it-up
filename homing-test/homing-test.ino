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

#define zHeightPin 18

#define YMAX 2000
#define XMAX 2000

// Define initial switch states
int xSS = 0;
int ySS = 0;
int zSS = 0;
int ledPin = 13;

// Define xyz coordinates 
int xPos = 0;
int yPos = 0;
int zPos = 0;

int xEND = false;
int yEND = false;


void setup() {
  Serial.begin(9600);
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);

  pinMode(zCurrentPin, INPUT);
  pinMode(zHeightPin, INPUT);

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
  delayMicroseconds(10000);
}



// Sequence to move to 0,0 and set the motors home
void homingSequence() {
  // Home X
  while(!digitalRead(xSwitchPin)) {
    digitalWrite(xDirPin, HIGH);
    for (int i = 0; i < stepsPerRevolution; i++) {
      xPos -=1;
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
      yPos -= 1;
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
      zPos -= 1;
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


// Check the height switch to see if the chalk should be pushed down.
void checkHeight() {
  while(digitalRead(zHeightPin)) {
    digitalWrite(zDirPin, LOW);
    zPos += 1;
    digitalWrite(zStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(zStepPin,LOW);
    delayMicroseconds(1000);
  }
  delayMicroseconds(25);
}

// Move to the end of X
void travelX() {
  while (xPos <= XMAX) {
    digitalWrite(xDirPin, LOW);
    xPos += 1;
    digitalWrite(xStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(xStepPin,LOW);
    delayMicroseconds(1000);
    Serial.print(xPos);
  }
  
  delayMicroseconds(1000000); //wait 1 s
}

// Move to the end of Y
void travelY() {
  while (yPos <= YMAX) {
    digitalWrite(yDirPin, LOW);
    yPos += 1;
    digitalWrite(yStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(yStepPin,LOW);
    delayMicroseconds(1000);
  }
}

void moveToCenter() {
  while (yPos != 1000) {
    if (yPos + 1 > YMAX) {
      break;
    } else if (yPos < 1000) {
      yPos += 1;
      digitalWrite(yDirPin, LOW);
      digitalWrite(yStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(yStepPin,LOW);
      delayMicroseconds(1000);
    } else if (yPos > 1000) {
      yPos -= 1;
      digitalWrite(yDirPin, HIGH);
      digitalWrite(yStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(yStepPin,LOW);
      delayMicroseconds(1000);
    }
  }
  while (xPos != 1000) {
    if (xPos + 1 > XMAX) {
      break;
    } else if (xPos < 1000) {
      xPos += 1;
      digitalWrite(xDirPin, LOW);
      digitalWrite(xStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(xStepPin,LOW);
      delayMicroseconds(1000);
      checkHeight(); 
    } else if (xPos > 850) {
      xPos -= 1;
      digitalWrite(xDirPin, HIGH);
      digitalWrite(xStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(xStepPin,LOW);
      delayMicroseconds(1000);
      checkHeight(); 
    }
  }
}

void loop() {

  travelX();

  delayMicroseconds(1000000);

  homingSequence();

  delayMicroseconds(1000000);

  moveToCenter();

  while(true) // remain here until told to break
  {
    if(Serial.available() > 0 ) // did something come in?
      if(Serial.read() == 'C') // is that something the char G?
        break;
  }  
  
}
