#ifndef BUTTON_H
#include <Arduino.h>
#include "component.h"

class Button : public Component {

  private:
    uint8_t     _pin;
    int         _pressDur;
    int         _currPress;
    uint8_t     _state;

    void        _toggleState();

  public:
                Button(uint8_t pin, int pressDur);
                ~Button();

    uint8_t     isPressed();
    void        update();
    int         signal();
};

#endif
