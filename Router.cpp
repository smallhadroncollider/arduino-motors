#include "Router.h"

Router::Router(Motor &a, Motor &b) : motorA(a), motorB(b) {}

void Router::setFlipped() { flip = true; }

void Router::setStandard() { flip = false; }

void Router::updateMotorA(byte speed, bool forward) {
  flip ? motorB.update(speed, forward) : motorA.update(speed, forward);
}

void Router::updateMotorB(byte speed, bool forward) {
  flip ? motorA.update(speed, forward) : motorB.update(speed, forward);
}
