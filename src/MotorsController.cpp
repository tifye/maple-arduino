#include "MotorsController.h"

MotorsController::MotorsController(): MonoBehaviour() {
  motorsHandle = MotorsHandle();

  setSpeed(50);
}

void MotorsController::loop() {
  motorsHandle.GetMotorEncoderLeft().loop();
  motorsHandle.GetMotorEncoderRight().loop();
}

void MotorsController::setSpeed(int speed) {
  setLeftSpeed(speed);
  setRightSpeed(speed);
}

void MotorsController::setLeftSpeed(int speed) {
  motorsHandle.GetMotorEncoderLeft().setTarPWM(speed);
}

void MotorsController::setRightSpeed(int speed) {
  motorsHandle.GetMotorEncoderRight().setTarPWM(speed);
}
