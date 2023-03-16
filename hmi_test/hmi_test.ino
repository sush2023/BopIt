#include <math.h>
#include <Arduino.h>

//x=180

int i = 0;
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1

int x_val = 0;
int y_val = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  int sensorValue = analogRead(A0); 
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
  
//  if (i==18){
//    i=0;
//    delay (2000);
//  }
//  else if(i==0){
//    delay(2000);
//  }
//
//  Serial.print("page ");
//  Serial.print(i); 
//  Serial.write(0Xff);
//  Serial.write(0Xff);
//  Serial.write(0Xff);
//  delay(200);
//  i++;


//joystick
  int xValue = analogRead(VRX_PIN)-507;
  int yValue = analogRead(VRY_PIN)-511;
  double deg = atan2(yValue, xValue)* 57.295779513082320876798154814105; 
  

//  Serial.print("x = ");
//  Serial.print(xValue);
//  Serial.print(", y = ");
//  Serial.println(yValue); 
//  Serial.print("degrees");
//  Serial.println(deg);
  Serial.print("aim_0.val=");
  Serial.print(int(deg));
  Serial.write(0Xff);
  Serial.write(0Xff);
  Serial.write(0Xff);
  delay(100);
}
