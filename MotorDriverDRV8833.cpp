#include "MotorDriverDRV8833.h"

MotorDriverDRV8833::MotorDriverDRV8833(byte in1_pin, byte in2_pin) {
  this->in1_pin = in1_pin;
  this->in2_pin = in2_pin;
}

void MotorDriverDRV8833::setup() {
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
}

void MotorDriverDRV8833::set(byte speed, bool forward) {
  analogWrite(forward ? in1_pin : in2_pin, speed);
  digitalWrite(in1_pin, forward ? HIGH : LOW);
  digitalWrite(in2_pin, forward ? LOW : HIGH);
}
