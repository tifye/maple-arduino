#include "LineSensor.h"

LineSensor::LineSensor() {
  pLineFollower = new MeLineFollower(PORT_8);
  sensorState = NONE_STATE;
}

LineSensor::~LineSensor() {
  delete pLineFollower;
}	

SensorState LineSensor::getSensorState(int sensorsReading) {
  SensorState sensorState = NONE_STATE;
  switch (sensorsReading) {
    case S1_IN_S2_IN:
      sensorState = BLACK_BLACK;
      break;
    case S1_IN_S2_OUT:
      sensorState = BLACK_WHITE;
      break;
    case S1_OUT_S2_IN:
      sensorState = WHITE_BLACK;
      break;
    case S1_OUT_S2_OUT:
      sensorState = WHITE_WHITE;
      break;
    default:
      sensorState = NONE_STATE;
      break;
  }

  Serial.println("\n");
  return sensorState;
}

void LineSensor::loop() {
  int sensorsReading = pLineFollower->readSensors();
  SensorState newSensorState = getSensorState(sensorsReading);
  sensorState = newSensorState;
}