#include "ModeWarthog.h"

ModeWarthog::ModeWarthog(ControllerPtr &controller, Router &router)
    : controller(controller), router(router) {}

void ModeWarthog::update() {
  int leftX = constrain(controller->axisX() / 2, -255, 255);
  int leftY = constrain(controller->axisY() / 2, -255, 255);

  router.updateMotorA(abs(leftX), leftX > 0);
  router.updateMotorB(abs(leftY), leftY < 0);
}
