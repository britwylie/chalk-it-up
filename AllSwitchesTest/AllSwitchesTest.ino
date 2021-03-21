// Define limit switch pins
#define xSwitchPin 8
#define ySwitchPin 10
#define zSwitchPin 11

int xSwitchState = 0;
int ySwitchState = 0;
int zSwitchState = 0;

void setup() {
  // Declare limit switches and current sensor as input:
  pinMode(xSwitchPin, INPUT);
  pinMode(ySwitchPin, INPUT);
  pinMode(zSwitchPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (xSwitchState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if (ySwitchState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if (zSwitchState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else digitalWrite(LED_BUILTIN, LOW);
}
