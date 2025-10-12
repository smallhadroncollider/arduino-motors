#include "Motor.h"

Motor::Motor(char id, byte en_pin, byte in1_pin, byte in2_pin) {
  this->id = id;
  this->en_pin = en_pin;
  this->in1_pin = in1_pin;
  this->in2_pin = in2_pin;
}

void Motor::setup() {
  pinMode(en_pin, OUTPUT);
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
}

void Motor::setFlipped() {
  flip = true;
  Serial.printf("Flipped motor %c config\n", id);
}

void Motor::setStandard() {
  flip = false;
  Serial.printf("Standard motor %c config\n", id);
}

void Motor::update(byte speed, bool forward) {
  // the motors whine if they're too slow
  byte normalisedSpeed = speed > 50 ? speed : 0;
  analogWrite(en_pin, normalisedSpeed);

  bool dir = flip ? !forward : forward;
  digitalWrite(in1_pin, dir ? HIGH : LOW);
  digitalWrite(in2_pin, dir ? LOW : HIGH);

  logToSerial(normalisedSpeed, dir);
}

void Motor::logToSerial(byte speed, bool forward) {
  if (log) {
    Serial.printf("Motor %c [Speed: %d, %s]\n", id, speed,
                  forward ? "Forward" : "Reverse");
  }
}
