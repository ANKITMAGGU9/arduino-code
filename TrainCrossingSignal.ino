// Define the pins for the LEDs
int redled=10; 
int greenled=12;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 10 and 12 as an output.
pinMode(redled,OUTPUT);
pinMode(greenled,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Turn on the first led (redled) and turn off the second led (greenled)
  digitalWrite(redled, HIGH);
  digitalWrite(greenled, LOW);
  // Delay for half a second (500 milliseconds)
  delay(500);
  // Turn off the first led (redled) and turn on the second led (greenled)
  digitalWrite(redled, LOW);
  digitalWrite(greenled, HIGH);
  // Delay for half a second (500 milliseconds)
  delay(500);
}
