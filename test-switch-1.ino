void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
}

int val;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 13; // LED Location

int sensorValue = 0;        // value read from the switch
int outputValue = 0;        // value output to the LED

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  //change analog out value:
  analogWrite(analogOutPin, outputValue);

  // print to the monitor
  Serial.print("analog 0 is: ");
  Serial.println(val);


  // wait 25 milliseconds
  delay(25);
}
