
int progressbar = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int sensorValue = analogRead(A0); 
}

void loop() {
  // put your main code here, to run repeatedly:

//  if (progressbar < 100){
//    progressbar += 1; 
//    delay(100); 
//  }
//  else{
//    progressbar = 0; 
//  }

//  
  double sensorValue = analogRead(A0); 
  sensorValue = sensorValue/10.23;
//  Serial.println(sensorValue);
  Serial.print("j0.val=");
  Serial.print(sensorValue,0);
  Serial.write(0Xff);
  Serial.write(0Xff);
  Serial.write(0Xff);
//  delay(1); 
}
