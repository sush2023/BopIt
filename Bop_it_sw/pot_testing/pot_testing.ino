void setup() {
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(8);

  int sensorValue = analogRead(A1);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(sensorValue);
}