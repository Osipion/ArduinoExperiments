#include "timer.h"

Timer::Timer(int interval) {
  this->_interval = interval;
  this->_startMs = millis();
  this->_intervalStartMs = 0U;
}

Timer::~Timer() {

}


int Timer::isElapsed() {
  if(millis() - this->_intervalStartMs >= this->_interval) {
    return 1;
  }
  return 0;
}

void Timer::resetInterval() {
  this->_intervalStartMs = millis();
}

unsigned long Timer::getTotal() {
  return millis() - this->_startMs;
}
