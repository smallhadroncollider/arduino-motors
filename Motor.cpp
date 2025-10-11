#include "Motor.h"

Motor::Motor(byte en_pin, byte in1_pin, byte in2_pin) {
  this->en_pin = en_pin;
  this->in1_pin = in1_pin;
  this->in2_pin = in2_pin;
}

void Motor::setup() {
  pinMode(en_pin, OUTPUT);
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
}

void Motor::setFlipped() { flip = true; }

void Motor::setStandard() { flip = false; }

void Motor::update(byte speed, bool forward) {
  // the motors whine if they're too slow
  analogWrite(en_pin, speed > 50 ? speed : 0);

  digitalWrite(flip ? in2_pin : in1_pin, forward ? HIGH : LOW);
  digitalWrite(flip ? in1_pin : in2_pin, forward ? LOW : HIGH);
}
