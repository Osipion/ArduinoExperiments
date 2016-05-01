#ifndef TIMER_H

#include <Arduino.h>

class Timer {

  private:
    unsigned long     _startMs;
    unsigned long     _intervalStartMs;
    unsigned int      _interval;

  public:
                      Timer(int interval);
                      ~Timer();

    int               isElapsed();
    void              resetInterval();
    unsigned long     getTotal();
};

#endif
