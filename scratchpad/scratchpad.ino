#define VERBOSE
#include "component.h"
#include "timer.h"
#include "button.h"
#include "LED.h"
#include "LDR.h"

/*******************************************************************************
 * BOARD CONFIG
 ******************************************************************************/

#define LED_PIN 7
#define BUTTON_PIN 2
#define BAUD 9600

/*******************************************************************************
 * TIMERS
 ******************************************************************************/

//Timer ledPrintTimer(1000);

/*******************************************************************************
 * COMPONENTS
 ******************************************************************************/

#define BUTTON 0
#define LIGHT0 1
#define COMPONENT_COUNT 2

Button button(BUTTON_PIN, 15);
LED light0(LED_PIN);

Component* components[COMPONENT_COUNT];

void assignComponents() {
  components[BUTTON] = &button;
  components[LIGHT0] = &light0;
}

void updateComponents() {
  for(int i = 0; i < COMPONENT_COUNT; i++) {
    components[i]->update();
  }
}

/*******************************************************************************
 * METHODS
 ******************************************************************************/


void buttonListener(uint8_t state) {
    light0.toggle();
}

/*******************************************************************************
 * MAIN
 ******************************************************************************/

void setup() {
  Serial.begin(BAUD);
  assignComponents();
  button.sendUpdatesTo(buttonListener);
}


void loop() {
  updateComponents();
}
