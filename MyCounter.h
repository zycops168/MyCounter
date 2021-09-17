#ifndef _MYCOUNTER_H_
#define _MYCOUNTER_H_

#include <Arduino.h>

class MyCounter {
  
private: // private data
  int btnPin;
  int ledPin;
  int timeSecond;
  bool btnPinActive;
  bool ledPinActive;
  
  uint32_t _next;



public: // public method
  // constructor
  MyCounter(const int btnPin,
            const int ledPin,
            const int timeSecond = 10,
            const bool btnPinActive = LOW,
            const bool ledPinActive = LOW);

  ~MyCounter();

  // set time second
  void setTimeSecond(const int timeSecond);

  // loop (event handler)
  void loop();

};

#endif
