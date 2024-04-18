// Define the pin connected to the LED
#define LED_PIN 5

void setup() {
  // Set pin 5 as an output
  pinMode(LED_PIN, OUTPUT);

  // Define the register addresses
  unsigned char* ddrd = (unsigned char*) 0x2A;
  unsigned char* ocr0b = (unsigned char*) 0x48;
  unsigned char* tccr0a = (unsigned char*) 0x44;
  unsigned char* tccr0b = (unsigned char*) 0x45;

  // Set pin 5 as an output using DDRD register
  *ddrd |= 1 << 5;

  // Set OCR0B register to control PWM (if needed)
  *ocr0b = 127;

  // Configure TCCR0A and TCCR0B registers for Timer/Counter0
  *tccr0a = 0b00100011;
  *tccr0b = 0b00000001;   //Set the Pre-scaler to 64

  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Toggle the LED
  digitalWrite(LED_PIN, HIGH);
  delay(500); // Wait for 500 milliseconds
  digitalWrite(LED_PIN, LOW);
  delay(500); // Wait for 500 milliseconds

  // Print the state of the LED to Serial
  Serial.println(digitalRead(LED_PIN));
}
