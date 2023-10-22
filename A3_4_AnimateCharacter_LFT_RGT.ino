#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte characterFrames[2][8] = {
  {
    B00100,
    B01110,
    B10101,
    B00100,
    B01110,
    B10101,
    B00100,
    B01010
  },
  {
    B00100,
    B01110,
    B10101,
    B00100,
    B01110,
    B10101,
    B00100,
    B10001
  }
};

int characterPosition = 7;  // Initial position of the character
int currentFrame = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1, characterFrames[currentFrame]);
  lcd.setCursor(characterPosition, 1);
  lcd.write(1);

  // Configure buttons as INPUT
  pinMode(6, INPUT);  // Button for moving left
  pinMode(7, INPUT);  // Button for moving right
}

void loop() {
  // Check for button presses and move the character accordingly
  if (digitalRead(6) == HIGH) {  // Assuming button for moving left is connected to pin 6
    moveCharacterLeft();
  } else if (digitalRead(7) == HIGH) {  // Assuming button for moving right is connected to pin 7
    moveCharacterRight();
  }

  // Animate the character
  animateCharacter();

  delay(100);  // Add a small delay to debounce the buttons
}

void moveCharacterLeft() {
  if (characterPosition > 0) {
    lcd.clear();
    characterPosition--;
    lcd.setCursor(characterPosition, 1);
    lcd.write(1);
  }
}

void moveCharacterRight() {
  if (characterPosition < 15) {
    lcd.clear();
    characterPosition++;
    lcd.setCursor(characterPosition, 1);
    lcd.write(1);
  }
}

void animateCharacter() {
  // Alternate between frames for animation
  currentFrame = 1 - currentFrame;

  lcd.clear();
  lcd.setCursor(characterPosition, 1);
  lcd.write(1);
  lcd.createChar(1, characterFrames[currentFrame]);
}
