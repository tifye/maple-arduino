#include <Arduino.h>
#include "MonoBehaviourManager.h"
#include "MotorsController.h"

MotorsController motorsController;

void setup() {
  Serial.begin(9600);

  motorsController.setSpeed(50);
}

void loop() {
  MonoBehaviourManager::getInstance().loop();
}
