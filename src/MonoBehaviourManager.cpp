#include "MonoBehaviourManager.h"

MonoBehaviourManager::MonoBehaviourManager() {
  monoBehaviours = {};
}

void MonoBehaviourManager::RegisterMonoBehaviour(Loopy* loopyInstance) {
  monoBehaviours.push_back(loopyInstance);
}

void MonoBehaviourManager::loop() {
  for(Loopy* pLoopy : monoBehaviours) {
    pLoopy->loop();
  }
}