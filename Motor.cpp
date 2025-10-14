#include "Motor.h"

Motor::Motor(char id, MotorDriver &driver) : driver(driver) { this->id = id; }

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
  bool dir = flip ? !forward : forward;

  driver.set(normalisedSpeed, dir);
  logToSerial(normalisedSpeed, dir);
}

void Motor::logToSerial(byte speed, bool forward) {
  if (log) {
    Serial.printf("Motor %c [Speed: %d, %s]\n", id, speed,
                  forward ? "Forward" : "Reverse");
  }
}
