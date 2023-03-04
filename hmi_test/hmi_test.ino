
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int sensorValue = analogRead(A0); 
}

void loop() {
//  double sensorValue = analogRead(A0); 
//  sensorValue = sensorValue/10.23;
//  Serial.print("j0.val=");
//  Serial.print(sensorValue,0);
//  Serial.write(0Xff);
//  Serial.write(0Xff);
//  Serial.write(0Xff);
//  delay(1); 
  
  if (i==8){
    i=0;
    delay (2000);
  }
  else if(i==0){
    delay(2000);
  }

  Serial.print("page ");
  Serial.print(i); 
  Serial.write(0Xff);
  Serial.write(0Xff);
  Serial.write(0Xff);
  delay(200);
  i++;
}
