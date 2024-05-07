volatile unsigned long ms;
unsigned char* tccr2a = (unsigned char*)0xB0;
unsigned char* tccr2b = (unsigned char*)0xB1;
unsigned char* timsk2 = (unsigned char*)0x70;
unsigned char* portd = (unsigned char*)0x2B;  // Pointer to Port D Data Register
unsigned char* ddrd = (unsigned char*)0x2A;   // Pointer to Data Direction Register for Port D
unsigned char* sreg = (unsigned char*)0x5F;
unsigned long previousTime;

ISR(TIMER2_OVF_vect) {
  ms++;
}

unsigned long getMilliseconds() {
  *timsk2 = 0;             // Disable timer2 interrupts
  unsigned long val = ms;  // Read the variable
  *timsk2 = 1;             // Re-enable timer2 interrupts
  return val;
}

void setup() {
  *ddrd |= (1 << 5);  // Set PD5 as output using bitwise OR to set only bit 5
  *tccr2a = 3;        // 8-bit Fast PWM on timer2
  *tccr2b = 4;        // Set pre-scaler to 64
  *sreg |= (1 << 7);  // Enable interrupts
  *timsk2 = 1;        // Enable timer2 overflow interrupt
}

void loop() {
  unsigned long currentTime = getMilliseconds();
  if ((*portd) & (1 << 5)) {  // If LED is currently ON
    if (currentTime - previousTime >= 1000) {
      *portd &= ~(1 << 5);  // Turn it OFF using bitwise AND and NOT to clear only bit 5
      previousTime = currentTime;
    }
  } else {  // If LED is currently OFF
    if (currentTime - previousTime >= 1000) {
      *portd |= (1 << 5);  // Turn it ON using bitwise OR to set only bit 5
      previousTime = currentTime;
    }
  }
}