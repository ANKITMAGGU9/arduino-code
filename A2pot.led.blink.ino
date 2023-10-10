  const int analogInPin = A0;  // Analog input pin for the potentiometer
const int ledPin = 9;      // LED connected to digital pin 13

int sensorValue = 0;        // Variable to store the potentiometer value
int blinkRate = 0;          // Variable to store the mapped blink rate

void setup() {
  Serial.begin(9600);       // Initialize serial communication at 9600 bits per second
  pinMode(ledPin, OUTPUT);   // Initialize the LED pin as an output
}

void loop() {
  // Read the potentiometer value
  sensorValue = analogRead(analogInPin);

  // Map the potentiometer value to the range of 10 to 1000 milliseconds for blink rate
  blinkRate = map(sensorValue, 0, 1023, 1000, 10);

  // Print the potentiometer value and mapped blink rate to the serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(sensorValue);
  Serial.print(", Blink Rate: ");
  Serial.println(blinkRate);

  // Blink the LED with the calculated blink rate
  digitalWrite(ledPin, HIGH);
  delay(blinkRate / 2);  // Divide by 2 because we want the total on/off cycle to be the blink rate
  digitalWrite(ledPin, LOW);
  delay(blinkRate / 2);  // Same as above

  delay(10);  // Small delay for stability
}
