#include "ModeSelector.h"

ModeSelector::ModeSelector(ControllerPtr &controller, Modes modes)
    : controller(controller), modes(modes) {
  this->modePtr = modes.car;
}

void ModeSelector::update() {
  if (controller->y() || controller->a()) {
    modePtr = modes.car;
  }

  if (controller->b()) {
    modePtr = modes.triggers;
  }

  modePtr->update();
}
