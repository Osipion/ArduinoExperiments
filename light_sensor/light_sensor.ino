#include "component.h"
#include "timer.h"
#include "button.h"
#include "LED.h"
#include "LDR.h"

/*******************************************************************************
 * BOARD CONFIG
 ******************************************************************************/

#define LED_PIN         7
#define BUTTON_PIN      2
#define LDR_PIN         A2
#define BAUD            9600

/*******************************************************************************
 * TIMERS
 ******************************************************************************/

//Timer ledPrintTimer(1000);

/*******************************************************************************
 * COMPONENTS
 ******************************************************************************/

#define BUTTON          0
#define LIGHT0          1
#define SENSOR0         2
#define COMPONENT_COUNT 3

Button      button      (BUTTON_PIN, 15);
LED         light0      (LED_PIN);
LDR         sensor0     (LDR_PIN);

Component*  components  [COMPONENT_COUNT];

void assignComponents() {
  components  [BUTTON]  = &button;
  components  [LIGHT0]  = &light0;
  components  [SENSOR0] = &sensor0;
}

void updateComponents() {
  for(int i = 0; i < COMPONENT_COUNT; i++) {
    components[i]->update();
  }
}

/*******************************************************************************
 * LISTENERS
 ******************************************************************************/


void buttonListener(int state) {
    light0.toggle();
}

void sensorListener(int state) {
  Serial.print("Light level is "); Serial.println(state);
}

/*******************************************************************************
 * MAIN
 ******************************************************************************/

void setup() {
  Serial.begin(BAUD);
  assignComponents();
  button.sendUpdatesTo(buttonListener);
  sensor0.setSampleRate(1000);
  sensor0.sendUpdatesTo(sensorListener);
}


void loop() {
  updateComponents();
}
