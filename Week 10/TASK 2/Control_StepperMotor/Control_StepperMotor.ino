#include <Stepper.h>

// Define the number of steps per revolution for your motor
const int stepsPerRevolution = 2048;  // For 28BYJ-48 stepper motor

// Initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

// Define button pins
const int buttonCW = 3;  // Button to move motor CW
const int buttonCCW = 4; // Button to move motor CCW

// Variables to store the previous state of the buttons
bool prevButtonCWState = HIGH;
bool prevButtonCCWState = HIGH;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set up the button pins as inputs with internal pull-up resistors
  pinMode(buttonCW, INPUT_PULLUP);
  pinMode(buttonCCW, INPUT_PULLUP);

  // Print initial state
  Serial.println("Stepper motor control setup complete.");
}

void loop() {
  // Read the state of the buttons
  bool buttonCWState = digitalRead(buttonCW);
  bool buttonCCWState = digitalRead(buttonCCW);

  // Check for changes in button CW state
  if (buttonCWState != prevButtonCWState) {
    if (buttonCWState == LOW) {
      // ButtonCW pressed, move motor CW
      myStepper.step(100);  // Adjust the number of steps per button press
      myStepper.setSpeed(5);
      Serial.println("Button CW pressed: Moving motor clockwise.");
    }
    prevButtonCWState = buttonCWState;
  }

  // Check for changes in button CCW state
  if (buttonCCWState != prevButtonCCWState) {
    if (buttonCCWState == LOW) {
      // ButtonCCW pressed, move motor CCW
      myStepper.step(-100);  // Adjust the number of steps per button press
      myStepper.setSpeed(5);
      Serial.println("Button CCW pressed: Moving motor counterclockwise.");
    }
    prevButtonCCWState = buttonCCWState;
  }
}
