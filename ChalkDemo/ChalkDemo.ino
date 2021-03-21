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

// Initialize homeStatus integer variable, keeps track of axes the bot has homed so far
// 0 = none homed, 1 = only z homed so far, 2 = z and x homed, 3 = all homed
int homeStatus = 0;

int xSwitchState = 0;
int ySwitchState = 0;
int zSwitchState = 0;

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

  // Home z
  while (homeStatus = 0) {
    // Set the spinning direction clockwise:
    digitalWrite(zDirPin, HIGH);
    // Spin the stepper motor 1 revolution quickly:
    for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(zStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(zStepPin, LOW);
      delayMicroseconds(1000);
      }
    if (zSwitchState == HIGH) homeStatus = 1;
  }

  // Home x
  while (homeStatus = 1) {
    // Set the spinning direction clockwise:
    digitalWrite(xDirPin, HIGH);
    // Spin the stepper motor 1 revolution quickly:
    for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(xStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(xStepPin, LOW);
      delayMicroseconds(1000);
      }
    if (xSwitchState == HIGH) homeStatus = 2;
  }

  // Home y
  while (homeStatus = 2) {
    // Set the spinning direction clockwise:
    digitalWrite(yDirPin, HIGH);
    // Spin the stepper motor 1 revolution quickly:
    for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(yStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(yStepPin, LOW);
      delayMicroseconds(1000);
      }
    if (ySwitchState == HIGH) homeStatus = 3;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
