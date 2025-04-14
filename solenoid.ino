int solenoid = 3;

void setup() {
  pinMode(solenoid, OUTPUT);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read(); // Read incoming character
    if (input == 'a') {
      digitalWrite(solenoid, HIGH); // Activate solenoid
      delay(1000);                  // Keep it on for 1 second
      digitalWrite(solenoid, LOW);  // Deactivate
    }
  }
}