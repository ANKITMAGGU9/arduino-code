#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop()
{
  if (Serial.available()) {
    char name = Serial.read();
    Wire.beginTransmission(4); // transmit to device #4
    Wire.write(name);        // sends five bytes
    //Wire.write(x);              // sends one byte  
    Wire.endTransmission();    // stop transmitting

    //x++;
  }
}  
  