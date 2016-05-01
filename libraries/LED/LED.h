#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include "component.h"

class LED : public Component {

  private:
    uint8_t     _on;

  public:
                LED(uint8_t pin);
                ~LED();

    void        update();
    void        on();
    void        off();
    void        toggle();
    uint8_t     isOn();
};

#endif
