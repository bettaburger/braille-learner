// green wires, wired from left to right
const int solenoid1 = 2;
const int solenoid2 = 3; 
const int solenoid3 = 4;
// purple wires, wired from left to right
const int solenoid4 = 8;
const int solenoid5 = 9;
const int solenoid6 = 10;

// Braille cell labels
// 3 6
// 2 5
// 1 4 

// Joystick and button pins
const int joyX = A0;
const int button = 12;

// Alphabet letters
int letterIndex = 0;
String alphabet = "abcdefghijklmnopqrstuvwxyz"; // 0 - 25 or 26 letters
bool moved = false;

void setup() {
  pinMode(solenoid1, OUTPUT);
  pinMode(solenoid2, OUTPUT);
  pinMode(solenoid3, OUTPUT);
  pinMode(solenoid4, OUTPUT);
  pinMode(solenoid5, OUTPUT);
  pinMode(solenoid6, OUTPUT);

  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int xPosition = analogRead(joyX);

  // Joystick module, 
  // Most left 0
  // Most right 666
  // Middle around 327-328 read

  // Handle joystick movement
  if (!moved) {

    // Joystick is moved left, the letter before the current
    if (xPosition == 0 && letterIndex > 0) {
      letterIndex--;
      Serial.print("Previous letter: ");
      Serial.println(alphabet[letterIndex]);
      moved = true;
    }
    // Joystick is moved right, the letter after the current
    else if (xPosition >= 660 && letterIndex < 25) {
      letterIndex++;
      Serial.print("Next letter: ");
      Serial.println(alphabet[letterIndex]);
      moved = true;
    }
  }
 
  // Joystick is in the midddle, the current letter
  if (xPosition == 327 || xPosition == 328) {
    moved = false;
    Serial.print("Current letter: ");
    Serial.println(alphabet[letterIndex]);
  }

  // Handle button press, when the joystick button is pressed then
  // the letter will be translated into braille. 
  if (digitalRead(button) == LOW) {
    Serial.print("Selected letter: ");
    Serial.println(alphabet[letterIndex]);
    braille(alphabet[letterIndex]);
    delay(1000);
  }

  delay(100);
}

// Mimick the braille cells for the solenoid from a - z. 
void braille(char letter) {
  digitalWrite(solenoid1, LOW);
  digitalWrite(solenoid2, LOW);
  digitalWrite(solenoid3, LOW);
  digitalWrite(solenoid4, LOW);
  digitalWrite(solenoid5, LOW);
  digitalWrite(solenoid6, LOW);

  // A, turn s3
  if (letter == 'a') {
    digitalWrite(solenoid3, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid3, LOW);  // off
  }
  // B, turn s3, turn s2
  else if (letter == 'b') {
    digitalWrite(solenoid3, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid3, LOW);  // off

    digitalWrite(solenoid2, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid2, LOW);  // off
  } 
  // C, turn s3, turn s6
  else if (letter == 'c') {
    digitalWrite(solenoid3, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid3, LOW);  // off

    digitalWrite(solenoid6, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid6, LOW);  // off
  } 
  // D, turn s3, turn s6, turn, s5
  else if (letter == 'd') {
    digitalWrite(solenoid3, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid3, LOW);  // off

    digitalWrite(solenoid6, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid6, LOW);  // off

    digitalWrite(solenoid5, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid5, LOW);  // off
  }
  // E, turn s3, turn s5
  else if (letter == 'e') {
    digitalWrite(solenoid3, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid3, LOW);  // off

    digitalWrite(solenoid5, HIGH); // on
    delay(1000); // Have the sole up for 1000 milliseconds (1 seconds)
    digitalWrite(solenoid5, LOW);  // off
  }
  // F, turn s3, s6, s2
  else if (letter == 'f') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); 
    digitalWrite(solenoid3, LOW); 

    digitalWrite(solenoid6, HIGH); 
    delay(1000); 
    digitalWrite(solenoid6, LOW); 

    digitalWrite(solenoid2, HIGH); 
    delay(1000);
    digitalWrite(solenoid2, LOW);  
  }
  // G, turn s3, s6, s2, s5
  else if (letter == 'g') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid6, HIGH); 
    delay(1000); 
    digitalWrite(solenoid6, LOW);

    digitalWrite(solenoid2, HIGH); 
    delay(1000); digitalWrite(solenoid2, LOW);
    
    digitalWrite(solenoid5, HIGH); 
    delay(1000); 
    digitalWrite(solenoid5, LOW);
  } 
  // H, turn s3, s2, s5
    else if (letter == 'h') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); 
    digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid2, HIGH); 
    delay(1000); 
    digitalWrite(solenoid2, LOW);

    digitalWrite(solenoid5, HIGH); 
    delay(1000); 
    digitalWrite(solenoid5, LOW);
  } 
  // I, turn s6, s2 
  else if (letter == 'i') {
    digitalWrite(solenoid6, HIGH); 
    delay(1000); 
    digitalWrite(solenoid6, LOW);

    digitalWrite(solenoid2, HIGH); 
    delay(1000); 
    digitalWrite(solenoid2, LOW);
  } 
  // J, turn s6, s2, s5
  else if (letter == 'j') {
    digitalWrite(solenoid6, HIGH); 
    delay(1000); 
    digitalWrite(solenoid6, LOW);

    digitalWrite(solenoid5, HIGH); 
    delay(1000); 
    digitalWrite(solenoid5, LOW);

    digitalWrite(solenoid2, HIGH); 
    delay(1000); 
    digitalWrite(solenoid2, LOW);
  }
  // K, turn s3, s1  
  else if (letter == 'k') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); 
    digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid1, HIGH); 
    delay(1000); 
    digitalWrite(solenoid1, LOW);
  } 
  // If L, turn s3, s2, s1 
  else if (letter == 'l') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); 
    digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid2, HIGH); 
    delay(1000); 
    digitalWrite(solenoid2, LOW);

    digitalWrite(solenoid1, HIGH); 
    delay(1000); 
    digitalWrite(solenoid1, LOW);
  }
  // M, turn s3, s3, s1 
  else if (letter == 'm') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); 
    digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid6, HIGH); 
    delay(1000); 
    digitalWrite(solenoid6, LOW);

    digitalWrite(solenoid1, HIGH); 
    delay(1000); 
    digitalWrite(solenoid1, LOW);
  } 
  // N, turn s3, s6, s5, s1 
  else if (letter == 'n') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); 
    digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid6, HIGH); 
    delay(1000); 
    digitalWrite(solenoid6, LOW);

    digitalWrite(solenoid5, HIGH); 
    delay(1000); 
    digitalWrite(solenoid5, LOW);

    digitalWrite(solenoid1, HIGH); 
    delay(1000); 
    digitalWrite(solenoid1, LOW);
  } 
  // O, turn s3, s5, s1
  else if (letter == 'o') {
    digitalWrite(solenoid3, HIGH); 
    delay(1000); 
    digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid1, HIGH); 
    delay(1000); 
    digitalWrite(solenoid1, LOW);

    digitalWrite(solenoid5, HIGH); 
    delay(1000); 
    digitalWrite(solenoid5, LOW);
  } 
  // P, turn s3, s6, s2, s1
  else if (letter == 'p') {
      digitalWrite(solenoid3, HIGH);
      delay(1000);
      digitalWrite(solenoid3, LOW);

      digitalWrite(solenoid2, HIGH);
      delay(1000);
      digitalWrite(solenoid2, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid6, HIGH);
      delay(1000);
      digitalWrite(solenoid6, LOW);
  }
  // Q 
  else if (letter == 'q') {
      digitalWrite(solenoid3, HIGH);
      delay(1000);
      digitalWrite(solenoid3, LOW);

      digitalWrite(solenoid2, HIGH);
      delay(1000);
      digitalWrite(solenoid2, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid6, HIGH);
      delay(1000);
      digitalWrite(solenoid6, LOW);

      digitalWrite(solenoid5, HIGH);
      delay(1000);
      digitalWrite(solenoid5, LOW);
  }
  //R 
  else if (letter == 'r') {
      digitalWrite(solenoid3, HIGH);
      delay(1000);
      digitalWrite(solenoid3, LOW);

      digitalWrite(solenoid2, HIGH);
      delay(1000);
      digitalWrite(solenoid2, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid5, HIGH);
      delay(1000);
      digitalWrite(solenoid5, LOW);

  }
  // S
  else if (letter == 's') {
      digitalWrite(solenoid2, HIGH);
      delay(1000);
      digitalWrite(solenoid2, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid6, HIGH);
      delay(1000);
      digitalWrite(solenoid6, LOW);

  }
  // T 
  else if (letter == 't') {
      digitalWrite(solenoid2, HIGH);
      delay(1000);
      digitalWrite(solenoid2, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid6, HIGH);
      delay(1000);
      digitalWrite(solenoid6, LOW);

      digitalWrite(solenoid5, HIGH);
      delay(1000);
      digitalWrite(solenoid5, LOW);

  }
  // U
  else if (letter == 'u') {
      digitalWrite(solenoid3, HIGH);
      delay(1000);
      digitalWrite(solenoid3, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid4, HIGH);
      delay(1000);
      digitalWrite(solenoid4, LOW);

  } 
  // V
  else if (letter == 'v') {
      digitalWrite(solenoid3, HIGH);
      delay(1000);
      digitalWrite(solenoid3, LOW);

      digitalWrite(solenoid2, HIGH);
      delay(1000);
      digitalWrite(solenoid2, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid4, HIGH);
      delay(1000);
      digitalWrite(solenoid4, LOW);
  }
  // w
  else if (letter == 'w') {
    digitalWrite(solenoid2, HIGH); 
    delay(1000); 
    digitalWrite(solenoid2, LOW);

    digitalWrite(solenoid6, HIGH); 
    delay(1000); 
    digitalWrite(solenoid6, LOW);

    digitalWrite(solenoid5, HIGH); 
    delay(1000); 
    digitalWrite(solenoid5, LOW);

    digitalWrite(solenoid4, HIGH); 
    delay(1000); 
    digitalWrite(solenoid4, LOW);

  } 
  // x
  else if (letter == 'x') {
    digitalWrite(solenoid3, HIGH);
    delay(1000);
    digitalWrite(solenoid3, LOW);

    digitalWrite(solenoid1, HIGH);
    delay(1000);
    digitalWrite(solenoid1, LOW);

    digitalWrite(solenoid6, HIGH);
    delay(1000);
    digitalWrite(solenoid6, LOW);

    digitalWrite(solenoid4, HIGH);
    delay(1000);
    digitalWrite(solenoid4, LOW);

  } // y 
  else if (letter == 'y') {
      digitalWrite(solenoid3, HIGH);
      delay(1000);
      digitalWrite(solenoid3, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid6, HIGH);
      delay(1000);
      digitalWrite(solenoid6, LOW);

      digitalWrite(solenoid5, HIGH);
      delay(1000);
      digitalWrite(solenoid5, LOW);

      digitalWrite(solenoid4, HIGH);
      delay(1000);
      digitalWrite(solenoid4, LOW);
  }
  // z
  else if (letter == 'z') {
      digitalWrite(solenoid3, HIGH);
      delay(1000);
      digitalWrite(solenoid3, LOW);

      digitalWrite(solenoid1, HIGH);
      delay(1000);
      digitalWrite(solenoid1, LOW);

      digitalWrite(solenoid5, HIGH);
      delay(1000);
      digitalWrite(solenoid5, LOW);

      digitalWrite(solenoid4, HIGH);
      delay(1000);
      digitalWrite(solenoid4, LOW);
    }
}
