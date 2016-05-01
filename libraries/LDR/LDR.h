#ifndef LDR_H
#define LDR_H

#include <Arduino.h>
#include "component.h"

class LDR : public Component {

  private:
    uint16_t    _sampleRate;
    uint32_t    _lastSample;

  public:
                LDR(uint8_t pin);
                ~LDR();

    int         signal();
    void        setSampleRate(uint16_t value);
    uint16_t    sampleRate();
    void        update();
};

#endif
