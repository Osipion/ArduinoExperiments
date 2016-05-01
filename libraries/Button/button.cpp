#include "button.h"

Button::Button(uint8_t pin, int pressDur) : Component(pin) {
  this->_pin = pin;
  this->_pressDur = pressDur;
  pinMode(pin, INPUT_PULLUP);
}



Button::~Button() {

}


void Button::_toggleState() {
  if(this->_state) {
    this->_state = 0U;
  }
  else {
    this->_state = 1U;
  }
  this->sendUpdate(this->_state);
#ifdef VERBOSE
  Serial.print("Button on pin ");
  Serial.print(this->_pin);
  Serial.print(" state changed: ");
  Serial.println(this->_state);
#endif
}



int Button::signal() {
  return digitalRead(this->_pin);
}



uint8_t Button::isPressed() {
  return this->_state;
}



void Button::update() {
  if(this->signal() == LOW) {
#ifdef VERBOSE
    Serial.print("Button on pin ");
    Serial.print(this->_pin);
    Serial.println(" starts to be pressed");
#endif
    this->_currPress++;
  }
  else {
    this->_currPress = 0;
  }
  if(this->_currPress >= this->_pressDur) {
#ifdef VERBOSE
    Serial.print("Button on pin ");
    Serial.print(this->_pin);
    Serial.println(" press cap reached.");
#endif
    this->_currPress = 0U;
    this->_toggleState();
  }
}
