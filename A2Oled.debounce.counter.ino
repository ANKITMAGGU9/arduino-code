
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pin connected to the button
const int switchPin = 2;

int lastButtonState = HIGH;
int buttonPressCount = 0;  // variable to count button presses

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  pinMode(switchPin, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(switchPin);

  if (reading != lastButtonState) {
    // reset the debounce counter
    delay(10);
    reading = digitalRead(switchPin);
    if (reading != lastButtonState) {

      lastButtonState = reading;

      // check if the button is pressed
      if (reading == HIGH) {
        buttonPressCount++;
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE); 
        display.setCursor(0,0);
        display.print("Button Pressed:");
        display.setCursor(64,16);
        display.print(buttonPressCount);
        display.display();
        
        Serial.print("You've pressed the button ");
        Serial.print(buttonPressCount);
        Serial.println(" times");
      }
    }
  }
}
