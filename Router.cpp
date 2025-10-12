#include "Router.h"

Router::Router(Motor *a, Motor *b) : motorA(a), motorB(b) {}

void Router::handleFlip(ControllerPtr &controller) {
  if (controller->buttons() == 0x0010) {
    setStandard();
  }

  if (controller->buttons() == 0x0020) {
    setFlipped();
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

void Router::logMotor(char motor, byte speed, bool forward) {
  if (log) {
    Serial.printf("Motor %c [Speed: %d, %s]\n", motor, speed,
                  forward ? "Forward" : "Reverse");
  }
}

void Router::setup() {
  motorA->setup();
  motorB->setup();
}

void Router::reset() { setStandard(); }

void Router::updateMotorA(byte speed, bool forward) {
  flip ? motorB->update(speed, forward) : motorA->update(speed, forward);
  logMotor(flip ? 'B' : 'A', speed, forward);
}

void Router::updateMotorB(byte speed, bool forward) {
  flip ? motorA->update(speed, forward) : motorB->update(speed, forward);
  logMotor(flip ? 'A' : 'B', speed, forward);
}
