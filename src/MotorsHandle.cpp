#include "MotorsHandle.h"

MeEncoderOnBoard MotorsHandle::MotorEncoderLeft(SLOT1);
MeEncoderOnBoard MotorsHandle::MotorEncoderRight(SLOT2);

MotorsHandle::MotorsHandle() {
  pMotorEncoderLeft = &MotorsHandle::MotorEncoderLeft;
  pMotorEncoderRight = &MotorsHandle::MotorEncoderRight;
  pMotorEncoderLeft->reset(SLOT1);
  pMotorEncoderRight->reset(SLOT2);

  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(WGM12);
  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);
  attachInterrupt(pMotorEncoderLeft->getIntNum(), isrProcessEncoderLeft, RISING);
  attachInterrupt(pMotorEncoderRight->getIntNum(), isrProcessEncoderRight, RISING);
}

MeEncoderOnBoard& MotorsHandle::GetMotorEncoderLeft() {
  return *pMotorEncoderLeft;
}

MeEncoderOnBoard& MotorsHandle::GetMotorEncoderRight() {
  return *pMotorEncoderRight;
}