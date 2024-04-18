// Define the pin connected to the LED
#define LED_PIN 5

void setup() {
  // Set pin 5 as an output
  pinMode(LED_PIN, OUTPUT);

  // Define the register addresses
  unsigned char* ddrd = (unsigned char*) 0x2A;
  unsigned char* ocr0a = (unsigned char*) 0x47;
  unsigned char* ocr0b = (unsigned char*) 0x48;
  unsigned char* tccr0a = (unsigned char*) 0x44;
  unsigned char* tccr0b = (unsigned char*) 0x45;

  // Set pin 5 as an output using DDRD register
  *ddrd |= 1 << 5;

  // Set OCR0A register to determine the top value
  *ocr0a = 5;

  // Set OCR0B register to control PWM
  // *ocr0b = 0; // Set OCR0B for 0% duty cycle
  // *ocr0b = *ocr0a / 4; // Set OCR0B for 25% duty cycle
  // *ocr0b = *ocr0a / 2; // Set OCR0B for 50% duty cycle
  // *ocr0b = (*ocr0a * 3) / 4; // Set OCR0B for 75% duty cycle
  *ocr0b = *ocr0a; // Set OCR0B equal to OCR0A for 100% duty cycle

  // Configure TCCR0A and TCCR0B registers for Timer/Counter0
  *tccr0a = 0b00100011; // Fast PWM mode, non-inverting
  *tccr0b = 0b00000001; // Set the pre-scaler to 1 (no prescaling)

  Serial.begin(9600);
}

void loop() {


  // Toggle the LED
  digitalWrite(LED_PIN, HIGH);
  delay(1000); // Wait for 500 milliseconds
  digitalWrite(LED_PIN, LOW);
  delay(1000); // Wait for 500 milliseconds

  // Print the state of the LED to Serial
  Serial.println(digitalRead(LED_PIN));
}
