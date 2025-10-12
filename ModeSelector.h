#pragma once

#include "ModeCar.h"
#include "ModeTriggers.h"
#include <Arduino.h>
#include <Bluepad32.h>

struct Modes {
  Mode *car;
  Mode *triggers;
  Mode *warthog;
};

class ModeSelector {
private:
  Mode *modePtr;
  Modes modes;
  ControllerPtr &controller;

  void setCarMode();
  void setTriggersMode();
  void setWarthogMode();

public:
  ModeSelector(ControllerPtr &controller, Modes modes);
  void reset();
  void update();
};
