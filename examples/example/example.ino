#include "MyCounter.h"

#define PIN_BUTTON  16 // external button pin
#define PIN_LED     LED_BUILTIN

// instand object by assigning button and led pins (with default setting)
MyCounter counter(PIN_BUTTON, PIN_LED);

void setup() {
  // serial setup
  Serial.begin(115200);
  
  // change counter time
  counter.setTimeSecond(5);
}

void loop() {
  // counter event handler
  counter.loop();

}
