#pragma once

#include "Mode.h"
#include "Router.h"

class ModeCar : public Mode {
private:
  ControllerPtr &controller;
  Router &router;

public:
  ModeCar(ControllerPtr &controller, Router &router);
  void update();
};
