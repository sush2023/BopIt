#define VRX_PIN  A2 // Arduino pin connected to VRX pin
#define VRY_PIN  A3 // Arduino pin connected to VRY pin
#define POT_PIN  A1 // Arduino pin connected to Potentiometer -- Input

//Input Variables
int xValue = 0 ; // To store value of the X axis for Joystick
int yValue = 0 ; // To store value of the Y axis for Joystick
int sensorValue = 0; //To store value from Potentiometer
int buttonState = 0; //To store value from Button

//Input Checks
bool powerRight; //Tells us if the power was right or not
bool buttonPressed = true; //Tells us if button was pressed

//Random Numbers
int randomStage = 0;
int randomPower = 0;

//Extra
bool continueGame = true; //Tells us if we want to continue game
int  totalPoints = 0;

//Time Variables
unsigned long totalTime; //Total time program has been running in miliseconds
unsigned long timeLimit = 5000; //Time Limit for each command


void collectInputs(){

  //Aim it
  totalTime = millis(); //Total time program has been running
  while((millis()-totalTime) <= timeLimit){
    xValue = analogRead(VRX_PIN);
  }

  //DISPLAY IF POWER SHOULD BE HIGH OR LOW
  if(randomPower = 1){
    //Display Power High on Screen or Sound
  }

  else{
    //Display Power Low on Screen or Sound
  }

  //Power It
  totalTime = millis(); //Total Time Program has been running
  while((millis()-totalTime) <= timeLimit){
    sensorValue = analogRead(POT_PIN);
    }

  //Checking to see if the power is right
  //Dont know sensor threshhold values yet so lets just say 50 for now
  if((randomPower = 1 && sensorValue >= 50) || (randomPower = 2 && sensorValue <50)){
    powerRight = true;
    }

  else{
    powerRight = false;
    }

  //Shoot It
  buttonPressed = false; //Set to false. If button pressed it will go to true
  totalTime = millis(); //Total Time Program has been running
  while((millis()-totalTime) <= timeLimit){
    buttonState = digitalRead(8);
    if(buttonState = HIGH){
      buttonPressed = true;
      break;
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);    //Buzzer
  pinMode(7, INPUT); //Button
  //int sensorValue = analogRead(A1) - POTENTIOMETER
  Serial.begin(9600);
}

//Timer goes for 5 to 2.5
void loop() {
  // put your main code here, to run repeatedly:

  //Display Start Picture
  while(true){
    buttonState = digitalRead(8);
    if(buttonState = HIGH){
      continueGame = true;//Sets it back to true because it is false when game restarted
      break; //Breaks out of loop at starts the game
    }
   }
  

  while(true){
    //Pick a random number between 1 and 2 to pick the stage
    randomStage = random(2);
    randomPower = random(2);

    //Stage 1 Right
    if(randomStage == 1){
      //Display Pic Right
      
      //Collect Inputs
      collectInputs();

      //Checking to see if success
      if(xValue >= 0 && powerRight == true && buttonPressed == true){
        //Display Pics For Success
        totalPoints++;
        break;
      }

      else{
        continueGame = false;
      }
    }
    
    
    
    //Stage 2 Left
    if(randomStage == 2){
      //Display Pic Left

      //Collect Inputs
      collectInputs();

      //Checking to see if success
      if(xValue < 0 && powerRight == true && buttonPressed == true){
        //Display Pics For Success
        totalPoints++;
        break;
      }

      else{
        continueGame = false;
      }
    }

    //Checks to see if we should continue game
    if(continueGame = false){
      //Display Miss Screen and Total Points for 10 Seconds
      delay(10000); //10 Seconds

      //Reset Visits
      totalPoints = 0; //Reset total points
      timeLimit = 5000; // Reset Time limit
      break;
    }

    //Checks to see if game won
    if(totalPoints = 50){
      //Display Winning Screen for 10 seconds
      delay(10000); //10 Seconds

      //Reset Visits
      totalPoints = 0; //Reset total points
      timeLimit = 5000; // Reset Time limit
      break;
    }

    //Decreases by 0.25 seconds every 5 points. Decreases to 2.5 Seconds by end of game
    if(totalPoints%5 == 0){
      timeLimit -= 250;

    }
  }
  
  
}
