int num_array[10][7] = {
  {1,1,1,1,1,1,0},    // 0
  {0,1,1,0,0,0,0},    // 1
  {1,1,0,1,1,0,1},    // 2
  {1,1,1,1,0,0,1},    // 3
  {0,1,1,0,0,1,1},    // 4
  {1,0,1,1,0,1,1},    // 5
  {1,0,1,1,1,1,1},    // 6
  {1,1,1,0,0,0,0},    // 7
  {1,1,1,1,1,1,1},    // 8
  {1,1,1,0,0,1,1}     // 9
};

// Define the pins for each segment (A-G) and common anode for each digit
int segmentPins[] = {6, 7, 8, 9, 10, 11, 12};  // Adjust the pin numbers based on your setup
int digitPins[] = {2, 3, 4, 5};  // Adjust the pin numbers based on your setup

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], HIGH);  // Turn off all segments initially
  }

  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW);  // Turn off all digits initially
  }
}

void loop() {
  // Cycle through each segment individually for all 4 digits at the same time
  for (int i = 0; i < 7; i++) {
    for (int digit = 0; digit < 4; digit++) {
      digitalWrite(digitPins[digit], HIGH);  // Turn on all digits at the same time
      
      for (int j = 0; j < 7; j++) {
        digitalWrite(segmentPins[j], j == i ? LOW : HIGH);
      }
    }
    
    delay(1000);  // Delay for 1 second for each segment
    
    // Turn off all digits
    for (int digit = 0; digit < 4; digit++) {
      digitalWrite(digitPins[digit], LOW);
    }
  }

  delay(1000);  // Wait for 1 second before moving to the next cycle

  // Display digits 0-9 on all 4 digits simultaneously
  for (int num = 0; num < 10; num++) {
    for (int digit = 0; digit < 4; digit++) {
      digitalWrite(digitPins[digit], HIGH);  // Turn on all digits at the same time
      
      for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], num_array[num][i] == 1 ? LOW : HIGH);
      }
    }
    
    delay(1000);  // Delay for 1 second for each digit
    
    // Turn off all digits
    for (int digit = 0; digit < 4; digit++) {
      digitalWrite(digitPins[digit], LOW);
    }
  }

  delay(1000);  // Wait for 1 second before moving to the next cycle
}
