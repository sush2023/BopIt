/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-joystick
 */
#include <math.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

int xValue = 0 ; // To store value of the X axis
int yValue = 0 ; // To store value of the Y axis


void setup() {
  Serial.begin(9600) ;
}

void loop() {
  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN)-507;
  yValue = analogRead(VRY_PIN)-511;

  double deg = atan2(yValue, xValue)* 57.295779513082320876798154814105;
  // Serial.print("x = ");
  // Serial.print(xValue);
  // Serial.print(", y = ");
  // Serial.println(yValue);
  Serial.print("aim_0.val=");
  Serial.print(int(deg));
  Serial.write(0Xff);
  Serial.write(0Xff);
  Serial.write(0Xff);
  delay(100);
  // converts the analog value to commands
  // reset commands
}
