#include "LDR.h"

LDR::LDR(uint8_t pin) : Component(pin) {
  this->_sampleRate = 10;
  pinMode(pin, INPUT);
}

LDR::~LDR() {

}

int LDR::signal() {
  int r = analogRead(this->pin());
  return r;
}

void LDR::setSampleRate(uint16_t value) {
  this->_sampleRate = value;
}

uint16_t  LDR::sampleRate() {
  return this->_sampleRate;
}

void LDR::update() {
    uint32_t now = millis();
    if(now - this->_lastSample >= this->_sampleRate) {
      this->sendUpdate(this->signal());
      this->_lastSample = now;
    }
}
