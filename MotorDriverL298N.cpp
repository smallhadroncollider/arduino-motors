#include "MotorDriverL298N.h"

MotorDriverL298N::MotorDriverL298N(byte en_pin, byte in1_pin, byte in2_pin) {
  this->en_pin = en_pin;
  this->in1_pin = in1_pin;
  this->in2_pin = in2_pin;
}

void MotorDriverL298N::setup() {
  pinMode(en_pin, OUTPUT);
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
}

void MotorDriverL298N::set(byte speed, bool forward) {
  analogWrite(en_pin, speed);
  digitalWrite(in1_pin, forward ? HIGH : LOW);
  digitalWrite(in2_pin, forward ? LOW : HIGH);
}
