# Arduino Nano ESP32-S3 + L298N Motor Driver + Xbox One Controller

## Setup

- Install Bluepad32
- Select `esp32-bluepad32` board

## To Do

- [ ] Shoulder pads to flip motor control
    - L1: motor A and motor B
    - R1: motor B and motor A
- [ ] D-Pad controls direction
    - Left / right d-pad change motor A's direction
    - Up / down d-pad change motor B's direction
- [ ] A / B / X / Y buttons change "mode"
    - Throttle mode: left throttle => left motor / right throttle => right motor
    - Car mode: left/right throttle => speed motor / left x-axis => steering motor
    - Warthog mode: left y-axis => speed motor / left x-axis => steering motor
- [ ] Right joystick controls max speed
    - Left / right d-pad change motor A's max speed
    - Up / down d-pad change motor B's max speed
