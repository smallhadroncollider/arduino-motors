#include <Bluepad32.h>
#include "Motor.h"

// compatabilty mode pinout
int D10 = 21;
int D9 = 18;
int D8 = 17;

int D3 = 6;
int D5 = 8;
int D4 = 7;

Motor motorA(D10, D9, D8);
Motor motorB(D3, D5, D4);

ControllerPtr controller;

void setup() {
  Serial.begin(115200);

  motorA.setup();
  motorB.setup();

  Serial.println("Waiting for controller to connect");

  BP32.setup(&onConnectedController, &onDisconnectedController);
}

void loop() {
  if (BP32.update() && controller && controller->isConnected() && controller->hasData()) {
    int a = constrain(controller->axisX() / 2, -255, 255);
    motorA.update(abs(a), a > 0);

    int b = constrain((controller->throttle() - controller->brake()) / 4, -255, 255);
    motorB.update(abs(b), b > 0);
  }

  vTaskDelay(1);
}
