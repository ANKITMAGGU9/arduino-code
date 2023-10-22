#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);

const int button1Pin = 6;
const int button2Pin = 7;

volatile int quarters = 0;
volatile int loonies = 0;
volatile float total = 0.00;

bool button1Pressed = false;
bool button2Pressed = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Total: $0.00");

  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  handleButton(button1Pin, button1Pressed, quarters);
  handleButton(button2Pin, button2Pressed, loonies);
}

void handleButton(int buttonPin, bool &buttonPressed, volatile int &counter) {
  if (digitalRead(buttonPin) == HIGH) {
    delay(50);  // Debounce
    if (digitalRead(buttonPin) == HIGH && !buttonPressed) {
      buttonPressed = true;
      counter++;
      updateTotal();
    }
  } else {
    buttonPressed = false;
  }
}

void updateTotal() {
  total = quarters * 0.25 + loonies;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Total: $");
  lcd.print(total, 2);
}
