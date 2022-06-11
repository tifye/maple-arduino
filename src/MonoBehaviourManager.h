#ifndef MonoBehaviourManager_H
#define MonoBehaviourManager_H

#include <ArduinoSTL.h>
#include "Loopy.h"

// Lazy init singleton cpp
// https://stackoverflow.com/a/1008289/14918676

class MonoBehaviourManager: public Loopy {
private:
  std::vector<Loopy*> monoBehaviours;

public:
  static MonoBehaviourManager& getInstance() {
    static MonoBehaviourManager instance;
    return instance;
  }

  void RegisterMonoBehaviour(Loopy* loopyInstance);
  void loop();

private:
  MonoBehaviourManager();

  MonoBehaviourManager(MonoBehaviourManager const&);
  void operator=(MonoBehaviourManager const&);

public:
  // MonoBehaviourManager(MonoBehaviourManager const&) = delete;
  // MonoBehaviourManager operator=(MonoBehaviourManager const&) = delete;
};


#endif
