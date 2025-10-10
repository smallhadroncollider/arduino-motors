#pragma once

#include "Mode.h"
#include "Router.h"

class ModeTriggers : public Mode {
private:
  ControllerPtr &controller;
  Router &router;

public:
  ModeTriggers(ControllerPtr &controller, Router &router);
  void update();
};
