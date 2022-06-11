#ifndef MotorsHandle_H
#define MotorsHandle_H

#include <MeAuriga.h>

class MotorsHandle {
private:
  MeEncoderOnBoard* pMotorEncoderRight; 
  MeEncoderOnBoard* pMotorEncoderLeft;

public:
  static MeEncoderOnBoard MotorEncoderRight; 
  static MeEncoderOnBoard MotorEncoderLeft;
  
public:
  static void isrProcessEncoderLeft(void)
  {
    if(digitalRead(MotorsHandle::MotorEncoderRight.getPortB()) == 0){
      MotorsHandle::MotorEncoderRight.pulsePosMinus();
    }else{
      MotorsHandle::MotorEncoderRight.pulsePosPlus();
    }
  }
  static void isrProcessEncoderRight(void)
  {
    if(digitalRead(MotorsHandle::MotorEncoderLeft.getPortB()) == 0){
      MotorsHandle::MotorEncoderLeft.pulsePosMinus();
    }else{
      MotorsHandle::MotorEncoderLeft.pulsePosPlus();
    }
  }

  MotorsHandle();
  MeEncoderOnBoard& GetMotorEncoderLeft();
  MeEncoderOnBoard& GetMotorEncoderRight();

};

#endif
