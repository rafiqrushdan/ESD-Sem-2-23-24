#define IN1_PIN  5 // Left PWM pin
#define IN2_PIN  6 // Right PWM pin 
#define PWM_PIN  9

void setup() {
  Serial.begin(9600);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  // wait for serial input
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'e': // extend
        analogWrite(PWM_PIN, 255);
        digitalWrite(IN1_PIN, HIGH);
        digitalWrite(IN2_PIN, LOW);
        break;
      case 'r': // retract
        analogWrite(PWM_PIN, 255);
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, HIGH);
        break;
      case 's': // stop
        analogWrite(PWM_PIN, 0);
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, LOW);
        break;
    }
  }
}
