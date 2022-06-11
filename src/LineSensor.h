#ifndef LineSensor_H
#define LineSensor_H

#include "MonoBehaviour.h"
#include "MeAuriga.h"

enum SensorState { NONE_STATE, BLACK_BLACK, BLACK_WHITE, WHITE_BLACK, WHITE_WHITE };

class LineSensor: public MonoBehaviour {
private:
  MeLineFollower* pLineFollower;
  SensorState getSensorState(int);

public:
  SensorState sensorState;

  LineSensor();
  ~LineSensor();
  void loop();
};

#endif // LineSensor_H