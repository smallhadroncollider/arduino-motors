#include "ModeCar.h"

ModeCar::ModeCar(ControllerPtr &controller, Router &router)
    : controller(controller), router(router) {}

void ModeCar::update() {
  int leftX = constrain(controller->axisX() / 2, -255, 255);
  int combinedTriggers =
      constrain((controller->throttle() - controller->brake()) / 4, -255, 255);

  router.updateMotorA(abs(leftX), leftX > 0);
  router.updateMotorB(abs(combinedTriggers), combinedTriggers > 0);
}
