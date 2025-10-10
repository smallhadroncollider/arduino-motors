#pragma once

#include <Arduino.h>
#include <Bluepad32.h>

class Mode {
public:
  virtual void update() = 0;
};
