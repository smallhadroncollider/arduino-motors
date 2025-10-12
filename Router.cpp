#include "Router.h"

#define L1 0x0010
#define R1 0x0020

#define D_UP 0x01
#define D_DOWN 0x02
#define D_RIGHT 0x04
#define D_LEFT 0x08

Router::Router(Motor *a, Motor *b) : motorA(a), motorB(b) {}

void Router::handleFlip(ControllerPtr &controller) {
  handleFlipMotors(controller);
  handleFlipMotorDirections(controller);
}

void Router::handleFlipMotors(ControllerPtr &controller) {
  switch (controller->buttons()) {
  case L1:
    setStandard();
    break;
  case R1:
    setFlipped();
    break;
  }
}

void Router::handleFlipMotorDirections(ControllerPtr &controller) {
  switch (controller->dpad()) {
  case D_LEFT:
    motorA->setStandard();
    break;
  case D_RIGHT:
    motorA->setFlipped();
    break;
  case D_UP:
    motorB->setStandard();
    break;
  case D_DOWN:
    motorB->setFlipped();
    break;
  }
}

void Router::setFlipped() {
  flip = true;
  Serial.println("Flipped motor config");
}

void Router::setStandard() {
  flip = false;
  Serial.println("Standard motor config");
}

void Router::setup() {
  motorA->setup();
  motorB->setup();
}

void Router::reset() {
  setStandard();
  motorA->setStandard();
  motorB->setStandard();
}

void Router::updateMotorA(byte speed, bool forward) {
  Motor *motor = flip ? motorB : motorA;
  motor->update(speed, forward);
}

void Router::updateMotorB(byte speed, bool forward) {
  Motor *motor = flip ? motorA : motorB;
  motor->update(speed, forward);
}
