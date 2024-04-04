#include <Arduino.h> // Include Arduino library for pinMode and digitalWrite functions

class Blinky {
  private:
    char port;
    int pin;
    unsigned long onTime;
    unsigned long offTime;
    unsigned long previousMillis;
    bool ledState;

  public:
    Blinky() {}

    void Initialize(char port, int pin, unsigned long onTime, unsigned long offTime) {
      this->port = port;
      this->pin = pin;
      this->onTime = onTime;
      this->offTime = offTime;
      this->ledState = LOW;
      pinMode(pin, OUTPUT);
    }

    void Refresh() {
      unsigned long currentMillis = millis();
      
      if (currentMillis - previousMillis >= (ledState ? offTime : onTime)) {
        ledState = !ledState;
        digitalWrite(pin, ledState);
        previousMillis = currentMillis;
      }
    }
};

Blinky leds[8];

void setup() {
  leds[0].Initialize('D', 0, 781, 515);
  leds[1].Initialize('D', 1, 2014, 1348);
  leds[2].Initialize('D', 2, 343, 573);
  leds[3].Initialize('D', 3, 678, 1839);
  leds[4].Initialize('D', 4, 342, 534);
  leds[5].Initialize('D', 5, 1478, 326);
  leds[6].Initialize('D', 6, 1859, 351);
  leds[7].Initialize('D', 7, 777, 888);
  
  for (;;) {
    for (int i = 0; i < 10; i++) {
      leds[i].Refresh();
    }
  }
}