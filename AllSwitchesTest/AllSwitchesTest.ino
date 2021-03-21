// Define limit switch pins
#define xSwitchPin 8
#define ySwitchPin 10
#define zSwitchPin 11

void setup() {
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (digitalRead(xSwitchPin) == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (digitalRead(ySwitchPin) == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (digitalRead(zSwitchPin) == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else digitalWrite(LED_BUILTIN, HIGH);
}
