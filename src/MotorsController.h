#ifndef MotorsController_H
#define MotorsController_H

#include "MonoBehaviour.h"
#include "MotorsHandle.h"

class MotorsController: public MonoBehaviour {
private:
    MotorsHandle motorsHandle;
  
public:
    MotorsController();
    void loop();
    void setSpeed(int speed);
    void setLeftSpeed(int speed);
    void setRightSpeed(int speed);
};

#endif
