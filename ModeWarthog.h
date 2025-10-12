#pragma once

#include "Mode.h"
#include "Router.h"

class ModeWarthog : public Mode {
private:
  ControllerPtr &controller;
  Router &router;

public:
  ModeWarthog(ControllerPtr &controller, Router &router);
  void update();
};
