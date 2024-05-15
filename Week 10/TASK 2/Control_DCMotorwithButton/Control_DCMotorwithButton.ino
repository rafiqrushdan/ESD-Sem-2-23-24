// Define pin connections
const int LPWM = 9;
const int RPWM = 10;
const int L_EN = 7;
const int R_EN = 8;
const int button1 = 3;  // Button to move motor CW
const int button2 = 4;  // Button to move motor CCW

// Variables to store the previous state of the buttons
bool prevButton1State = HIGH;
bool prevButton2State = HIGH;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up the motor driver pins as outputs
  pinMode(LPWM, OUTPUT);
  pinMode(RPWM, OUTPUT);

  // Set up the button pins as inputs
  pinMode(button1, INPUT_PULLUP);  // Use internal pull-up resistor
  pinMode(button2, INPUT_PULLUP);  // Use internal pull-up resistor



  // Print initial state
  Serial.println("Motor control setup complete.");
}

void loop() {
  // Read the state of the buttons
  bool button1State = digitalRead(button1);
  bool button2State = digitalRead(button2);

  // Check for changes in button 1 state
  if (button1State != prevButton1State) {
    if (button1State == LOW) {
      // Button1 pressed, move motor CW
      digitalWrite(LPWM, LOW);
      analogWrite(RPWM, 100);  // Adjust speed by changing the value 0-255
      Serial.println("Button 1 pressed: Moving motor clockwise.");
    } else {
      // Button1 released, stop motor
      digitalWrite(RPWM, LOW);
      Serial.println("Button 1 released: Motor stopped.");
    }
    prevButton1State = button1State;
  }

  // Check for changes in button 2 state
  if (button2State != prevButton2State) {
    if (button2State == LOW) {
      // Button2 pressed, move motor CCW
      digitalWrite(RPWM, LOW);
      analogWrite(LPWM, 100);  // Adjust speed by changing the value 0-255
      Serial.println("Button 2 pressed: Moving motor counterclockwise.");
    } else {
      // Button2 released, stop motor
      digitalWrite(LPWM, LOW);
      Serial.println("Button 2 released: Motor stopped.");
    }
    prevButton2State = button2State;
  }
}
