//ANKIT MAGGU W0488811
// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int greenLED = 3;
int redLED = 4;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}
// the loop routine runs over and over again forever:
void loop() {
    // Read the state of the button
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);  // delay in between reads for stability
  if (buttonState==HIGH){
  digitalWrite(greenLED,HIGH); //Button is pressed, turn on the greenLED and turn off the redLED
  digitalWrite(redLED,LOW);
  } else {
  digitalWrite(redLED,HIGH);  //Button is not pressed, turn off the greenLED and turn on the redLED
  digitalWrite(greenLED,LOW);
  }
}

