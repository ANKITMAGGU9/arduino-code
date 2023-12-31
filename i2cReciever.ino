#include <Wire.h>

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  Serial.begin(9600);
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  //Serial.println();
  if (Wire.available()) {
    while(Wire.available()) 
    {
      char c = Wire.read(); // receive byte as a character
      Serial.print(c);         // print the character
    }

  }
}
