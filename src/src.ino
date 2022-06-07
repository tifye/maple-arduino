#include <MeAuriga.h>
#include <SoftwareSerial.h>
#include "MotorController.h"

#define ALLLEDS        0
#define LEDNUM 12 // Auriga on-board light ring has 12 LEDs


MeRGBLed led(0, LEDNUM); // on-board LED ring, at port PORT0 (onbard)
MeLineFollower lineFinder(PORT_8);
MotorController mh = MotorController();

float j, f, k;
int m;

void setup() {
  Serial.begin(9600);
  led.setpin(44);

  MotorController mh = MotorController();
  m = MOTOR_FORWARD;
  mh.setSpeed(100);
  mh.move(m);
}

void loop() {
  // FIXME can make observer pattern to observe line sensor changes
  int sensorState = lineFinder.readSensors();
  switch(sensorState){ 
    case S1_IN_S2_IN:
      Serial.print("IN IN");
      setAllLEDs(255, 0, 0);
      break;
    case S1_IN_S2_OUT:
      setAllLEDs(255, 0, 0);
      break;
    case S1_OUT_S2_IN:
      setAllLEDs(255, 0, 0);
      break;
    case S1_OUT_S2_OUT:
      setAllLEDs(0, 0, 0);
      break;
    default:
      Serial.print("Default");
      setAllLEDs(0, 0, 0);
      break;
  }
  led.show();
  mh.update();
}

void setAllLEDs(int r, int g, int b) {
  for (uint8_t t = 0; t < LEDNUM; t++) {
      led.setColorAt(t, r, g, b); 
  }
}

void switchDirection() {
  if (m == MOTOR_BACKWARD) {
    m = MOTOR_FORWARD;
    mh.move(m);
  } else if (m == MOTOR_FORWARD) {
    m = MOTOR_BACKWARD;
    mh.move(m);
  }
}
