#include <Arduino.h>
#include "MonoBehaviourManager.h"
#include "MotorsController.h"
#include "LineSensor.h"

MotorsController motorsController;
LineSensor lineSensor;
MeBuzzer buzzer;

void setup() {
  Serial.begin(9600);
  buzzer.setpin(45);

  motorsController.setSpeed(0);
}

void loop() {
  MonoBehaviourManager::getInstance().loop();

  if (lineSensor.sensorState == WHITE_WHITE) {
    buzzer.tone(262, 50);
  }
}
