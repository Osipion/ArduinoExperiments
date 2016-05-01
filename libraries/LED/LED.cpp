#include "LED.h"

void writeState(const uint8_t p, const char* state) {
#ifdef VERBOSE
  Serial.print("LED on pin ");
  Serial.print(p);
  Serial.print(" ");
  Serial.println(state);
#endif
}


LED::LED(uint8_t pin) : Component(pin) {
  pinMode(pin, OUTPUT);
}

LED::~LED() {

}

void LED::update() {

}

void LED::on() {
  if(!this->_on) {
    digitalWrite(this->pin(), HIGH);
    this->_on = 1U;
    writeState(this->pin(), "ON");
  }
}

void LED::off() {
  if(this->_on) {
    digitalWrite(this->pin(), LOW);
    this->_on = 0U;
    writeState(this->pin(), "OFF");
  }
}

void LED::toggle() {
  if(this->_on) {
    this->off();
  }
  else {
    this->on();
  }
}

uint8_t LED::isOn() {
  return this->_on;
}
