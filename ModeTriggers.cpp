#include "ModeTriggers.h"

ModeTriggers::ModeTriggers(ControllerPtr &controller, Router &router)
    : controller(controller), router(router) {}

void ModeTriggers::update() {
  byte throttle = controller->throttle() / 4;
  byte brake = controller->brake() / 4;

  router.updateMotorA(throttle, true);
  router.updateMotorB(brake, true);
}
