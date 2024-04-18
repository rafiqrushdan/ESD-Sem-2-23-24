// Define the pin connected to the LED
#define LED_PIN 5

void setup() {
  // Set pin 5 as an output
  pinMode(LED_PIN, OUTPUT);

  // Define the register addresses

unsigned char* ddrb = (unsigned char*) 0x24;
unsigned char* ocr1al = (unsigned char*) 0x88;
unsigned char* tccr1a = (unsigned char*) 0x80;
unsigned char* tccr1b = (unsigned char*) 0x81;

*ddrb = 2; 
*ocr1al = 255; 
*tccr1a = 0b10000011;
*tccr1b = 0b00000010;

  Serial.begin(9600);
}

void loop() {


  // Toggle the LED
  digitalWrite(LED_PIN, HIGH);
  delay(1000); // Wait for 1000 milliseconds
  digitalWrite(LED_PIN, LOW);
  delay(1000); // Wait for 1000 milliseconds

  // Print the state of the LED to Serial
  Serial.println(digitalRead(LED_PIN));
}
