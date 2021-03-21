#include <MultiStepper.h>

// Define stepper motor connections and steps per revolution:
#define xDirPin 2
#define xStepPin 3
#define yDirPin 4
#define yStepPin 5
#define zDirPin 6
#define zStepPin 7
#define zM2 20
#define stepsPerRevolution 200

// Define limit switch pins
#define xSwitchPin 8
#define ySwitchPin 10
#define zSwitchPin 11

// Define current sensor
#define zCurrentPin 14

//Define electromagnet pin
#define emagPin 21

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Declare motors and electomagnet as output:
  pinMode(xStepPin, OUTPUT);
  pinMode(xDirPin, OUTPUT);
  pinMode(yStepPin, OUTPUT);
  pinMode(yDirPin, OUTPUT); 
  pinMode(zStepPin, OUTPUT);
  pinMode(zDirPin, OUTPUT); 
  pinMode(emagPin, OUTPUT);
  pinMode(zM2, OUTPUT);
 
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);
  pinMode(zCurrentPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(xSwitchPin) == HIGH) {
    // Set the spinning direction clockwise:
    digitalWrite(zDirPin, HIGH);
    // Set step size to 1/16 step
    digitalWrite(zM2, HIGH);
    // Spin the stepper motor 1 revolution quickly:
    //for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(zStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(zStepPin, LOW);
      delayMicroseconds(1000);

      // read the input on analog pin 0:
      int sensorValue = analogRead(A3);
      // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      float voltage = sensorValue * (5.0 / 1023.0);
      // print out the value you read:
      Serial.println(voltage);
      //}
  }
  
  else if (digitalRead(ySwitchPin) == HIGH) {
    // Set the spinning direction counterclockwise:
    digitalWrite(zDirPin, LOW);
    // Set step size to 1/16 step
    digitalWrite(zM2, HIGH);
    // Spin the stepper motor 1 revolution quickly:
    //for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(zStepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(zStepPin, LOW);
      delayMicroseconds(1000);
      
      // read the input on analog pin 0:
      int sensorValue = analogRead(A3);
      // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      float voltage = sensorValue * (5.0 / 1023.0);
      // print out the value you read:
      Serial.println(voltage);
      //}
  }
  
  else {
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
    // print out the value you read:
    Serial.println(voltage);
  }

}
