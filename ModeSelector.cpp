#include "ModeSelector.h"

ModeSelector::ModeSelector(ControllerPtr &controller, Modes modes)
    : controller(controller), modes(modes) {
  this->modePtr = modes.car;
}

void ModeSelector::reset() { setCarMode(); }

void ModeSelector::setCarMode() {
  modePtr = modes.car;
  Serial.println("Car mode");
}

void ModeSelector::setTriggersMode() {
  modePtr = modes.triggers;
  Serial.println("Triggers mode");
}

void ModeSelector::update() {
  if (controller->y()) {
    setCarMode();
  }

  if (controller->b()) {
    setTriggersMode();
  }

  modePtr->update();
}
