#ifndef COMPONENT_H
#define COMPONENT_H

#define VERBOSE //remove to disable debug prints for this build

#include <Arduino.h>

class Component {

  private:
    void          (* _listener)(int status);
    uint8_t       _pin;

  protected:
    void          sendUpdate(int status);

  public:

                  Component(uint8_t pin);

    virtual void  update() = 0;
    uint8_t       pin();
    virtual void  sendUpdatesTo(void (* listener)(int status));
};

#endif
