//define pins a variable
int pushButton = 2;
int greenLED = 3;
int redLED = 4;
int long lastButtonPressTime = 0; // start from 0
const long inactivityTimeout = 60000; // constant is used as 60 seconds will be fixed   
//define pins its function IO
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton); //reading button state on or off
  Serial.println(buttonState); //Checking button status on serial monitor
  
  if (buttonState == HIGH) {   // comparing button state with HIGH
    digitalWrite(greenLED, HIGH); //IF TRUE greenLED will glow and red will not glow
    digitalWrite(redLED, LOW);
    lastButtonPressTime = millis(); // Record the time of the button press
  } else {
    digitalWrite(greenLED, LOW); // if false greenLed will remain off and red will glow
    digitalWrite(redLED, HIGH);
    
    // Check if no button has been pressed for 60 seconds ,if true turn both led off
    if (millis() - lastButtonPressTime >= inactivityTimeout) {
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
    }
  }
}
