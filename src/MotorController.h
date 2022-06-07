#ifndef MotorController_h
#define MotorController_h

#include "Arduino.h"
#include <MeAuriga.h>

MeEncoderOnBoard motorEncoderRight(SLOT1);
MeEncoderOnBoard motorEncoderLeft(SLOT2);

#define MOTOR_LEFT 1
#define MOTOR_RIGHT 2
#define MOTOR_BACKWARD 3
#define MOTOR_FORWARD 4
#define MOTOR_STOP 5


class MotorController {
  private:
  int speed;
  int direction;

  static void isrProcessEncoderLeft(void)
  {
    if(digitalRead(motorEncoderRight.getPortB()) == 0){
      motorEncoderRight.pulsePosMinus();
    }else{
      motorEncoderRight.pulsePosPlus();
    }
  }
  static void isrProcessEncoderRight(void)
  {
    if(digitalRead(motorEncoderLeft.getPortB()) == 0){
      motorEncoderLeft.pulsePosMinus();
    }else{
      motorEncoderLeft.pulsePosPlus();
    }
  }
    
  public:
  MotorController() {
    speed = 0;

    TCCR1A = _BV(WGM10);
    TCCR1B = _BV(CS11) | _BV(WGM12);
    TCCR2A = _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS21);
    attachInterrupt(motorEncoderRight.getIntNum(), isrProcessEncoderLeft, RISING);
    attachInterrupt(motorEncoderLeft.getIntNum(), isrProcessEncoderRight, RISING);
  }

  void update() {
    motorEncoderRight.loop();
    motorEncoderLeft.loop();
  }

  void move(int direction)
  {
    int leftSpeed = 0;
    int rightSpeed = 0;
    if(direction == 1){
      leftSpeed = -speed;
      rightSpeed = speed;
    }else if(direction == 2){
      leftSpeed = speed;
      rightSpeed = -speed;
    }else if(direction == MOTOR_BACKWARD){
      leftSpeed = -speed;
      rightSpeed = -speed;
    }else if(direction == 4){
      leftSpeed = speed;
      rightSpeed = speed;
    }

    // For whatever reason, the motor controller is not working properly
    rightSpeed *= -1;

    motorEncoderRight.setTarPWM(rightSpeed);
    motorEncoderLeft.setTarPWM(leftSpeed);
  }

  void setSpeed(int speed) {
    this->speed = speed;
  }
};
#endif