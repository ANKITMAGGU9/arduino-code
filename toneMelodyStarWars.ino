#include "pitches.h"

// Define the melody for "Imperial March" (Star Wars) 
// Each note correspond to particular frequency which is saved in pitch.h library
int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4, NOTE_G5, NOTE_G4,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5,
  NOTE_E5, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4, NOTE_G5, NOTE_G4,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5,
  NOTE_E5, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4, NOTE_G5, NOTE_G4,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_D5, NOTE_F5, NOTE_A4,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_D5, NOTE_F5, NOTE_A4,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_AS4,
  NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_AS4,
  NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4, NOTE_G5, NOTE_G4,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5,
  NOTE_E5, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_AS4, NOTE_A4, NOTE_G5, NOTE_G4,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5
};

// Define the note durations for the melody
int noteDurations[] = {
  8, 8, 8, 4, 16, 16,
  8, 4, 16, 16, 8, 4,
  4, 4, 4, 4, 8,
  8, 8, 8, 4, 16, 16,
  8, 4, 16, 16, 8, 4,
  4, 4, 4, 4, 8,
  8, 8, 8, 4, 16, 16,
  8, 4, 16, 16, 8, 4,
  4, 4, 4, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 4,
  4, 4, 4,
  8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 4,
  4, 4, 4,
  8, 8, 8, 4, 16, 16,
  8, 4, 16, 16, 8, 4,
  4, 4, 4, 4, 8,
  8, 8, 8, 4, 16, 16,
  8, 4, 16, 16, 8, 4,
  4, 4, 4,
};


// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
void setup() {
  // initialize the SPEAKER pin as an output:
  pinMode(8, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(2, INPUT);
}

 void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn SPEAKER on:
    // Total 137 iteration to play
    for (int thisNote = 0; thisNote < 137; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    }
  } 
  else {
    // turn SPEAKER off:
    digitalWrite(8, LOW);
  }
  
}