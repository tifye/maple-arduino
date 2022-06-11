#ifndef MonoBehaviour_H
#define MonoBehaviour_H

#include "MonoBehaviourManager.h"
#include "Loopy.h"

class MonoBehaviour: public Loopy {
public:
  MonoBehaviour() {
    MonoBehaviourManager::getInstance().RegisterMonoBehaviour(this);
  }
};

#endif