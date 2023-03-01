
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(4);
  
  while (buttonState == HIGH){
    
    digitalWrite(2, HIGH); // sets the digital pin 13 on
    delay(500);            // waits for a second
    digitalWrite(2, LOW);  // sets the digital pin 13 off
    delay(500); 
    buttonState = digitalRead(4);
  }
}
