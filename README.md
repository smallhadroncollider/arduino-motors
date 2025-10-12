# Arduino Nano ESP32-S3 + L298N Motor Driver + Xbox One Controller

## Wiring

- Nano D10 -> L298N EN1
- Nano D9 -> L298N IN1
- Nano D8 -> L298N IN2
- Nano D5 -> L298N IN3
- Nano D4 -> L298N IN4
- Nano D3 -> L298N EN2

## Setup

- Install Bluepad32
- Select `esp32-bluepad32` board

## To Do

- [x] Shoulder pads to flip motor control
    - [x] L1: motor A and motor B
    - [x] R1: motor B and motor A
- [x] D-Pad controls direction
    - [x] Left / right d-pad change motor A's direction
    - [x] Up / down d-pad change motor B's direction
- [ ] A / B / X / Y buttons change "mode"
    - [x] Throttle mode: left throttle => left motor / right throttle => right motor
    - [x] Car mode: left/right throttle => speed motor / left x-axis => steering motor
    - [ ] Warthog mode: left y-axis => speed motor / left x-axis => steering motor
- [ ] Right joystick controls max speed
    - [ ] Left / right d-pad change motor A's max speed
    - [ ] Up / down d-pad change motor B's max speed
