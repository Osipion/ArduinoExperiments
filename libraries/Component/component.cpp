#include "component.h"

Component::Component(uint8_t pin) {
  this->_pin = pin;
}

uint8_t Component::pin() {
  return this->_pin;
}

void Component::sendUpdatesTo(void (* listener)(int status)) {
  this->_listener = listener;
}

void Component::sendUpdate(int status) {
  if(this->_listener != NULL) {
    this->_listener(status);
  }
}
