void setup() {
  Serial.begin(9600);
}

void loop() {
  // int buttonState = digitalRead(8);

//  int sensorValue = analogRead(A1);
//  float voltage = sensorValue * (5.0 / 1023.0);
//  Serial.println(sensorValue);


  double sensorValue = analogRead(A0); 
  sensorValue = sensorValue/10.23;
  Serial.print("power_0.val=");
  Serial.print(sensorValue,0);
  Serial.write(0Xff);
  Serial.write(0Xff);
  Serial.write(0Xff);
  delay(1); 
}
