// Define limit switch pins
#define xSwitchPin 8
#define ySwitchPin 10
#define zSwitchPin 11

int xSwitchState = 0;
int ySwitchState = 0;
int zSwitchState = 0;
int ledPin = 13;

void setup() {
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  if (digitalRead(xSwitchPin)) {
    digitalWrite(ledPin, HIGH);
  }
  else if (digitalRead(ySwitchPin)) {
    digitalWrite(ledPin, HIGH);
  }
  else if (digitalRead(zSwitchPin)) {
    digitalWrite(ledPin, HIGH);
  }
  else digitalWrite(ledPin, LOW);
  delay(25); //wait 25 ms
}
