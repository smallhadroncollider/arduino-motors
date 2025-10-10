#include "Motor.h"

Motor::Motor(int en_pin, int in1_pin, int in2_pin) {
  this->en_pin = en_pin;
  this->in1_pin = in1_pin;
  this->in2_pin = in2_pin;
}

void Motor::setup() {
  pinMode(en_pin, OUTPUT);
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
}

void Motor::update(int speed, bool forward) {
  // really slow speeds make a buzzing sound
  if (speed < 50) {
    speed = 0;
  }

  // write changes
  analogWrite(en_pin, speed);
  digitalWrite(in1_pin, forward ? HIGH : LOW);
  digitalWrite(in2_pin, forward ? LOW : HIGH);
}
