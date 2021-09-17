#include "MyCounter.h"

MyCounter::MyCounter(const int btnPin,
                     const int ledPin,
                     const int timeSecond,
                     const bool btnPinActive,
                     const bool ledPinActive) {

  this->btnPin = btnPin;
  this->ledPin = ledPin;
  this->btnPinActive = btnPinActive;
  this->ledPinActive = ledPinActive;

  setTimeSecond(timeSecond);

  pinMode(this->ledPin, OUTPUT);
  pinMode(this->btnPin, INPUT);

}

MyCounter::~MyCounter() {

}

void MyCounter::setTimeSecond(const int timeSecond) {
  this->timeSecond = timeSecond;
}

void MyCounter::loop() {
  int countDown = timeSecond;
  bool buttonWasLow = false;
  // read the state of the pushbutton and set a flag if it is low:
  if (digitalRead(btnPin) == btnPinActive)  {
    buttonWasLow = true;
  }
  // This if statement will only fire on the rising edge of the button input
  if (digitalRead(btnPin) == !btnPinActive && buttonWasLow)  {
    uint32_t cur = millis();
    uint32_t prev = cur;
    uint32_t timeSecondPrev = prev + ((timeSecond) * 1000);
    while (cur <= (timeSecondPrev)) {
      if (cur >= _next) {
        digitalWrite(ledPin, !digitalRead(ledPin));
        _next = cur + 500;
  
        // print when led is on
        if (digitalRead(ledPin) == this->ledPinActive) {

          if ( countDown == 0) {
            Serial.println("Time Up!!!");
          } else {
            Serial.print("Counter remian ");
            Serial.print(countDown--) ;
            Serial.println(" seconds");
          }
        }
      }
      cur = millis();
    }
    // reset the button low flag
    buttonWasLow = false;
  } else {
    // turn off led
    digitalWrite(ledPin, this->ledPinActive == LOW ? HIGH : LOW);
  }

}
