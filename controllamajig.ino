#include <Bluepad32.h>
#include "Router.h"

// compatabilty mode pinout
byte D10 = 21;
byte D9 = 18;
byte D8 = 17;

byte D3 = 6;
byte D5 = 8;
byte D4 = 7;

Motor motorA(D10, D9, D8);
Motor motorB(D3, D5, D4);
Router router(motorA, motorB);

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
    int leftX = constrain(controller->axisX() / 2, -255, 255);
    byte throttle = controller->throttle() / 4;
    byte brake = controller->brake() / 4;
    int combinedTriggers = throttle - brake;

    router.updateMotorA(abs(leftX), leftX > 0);
    router.updateMotorB(abs(combinedTriggers), combinedTriggers > 0);
  }

  vTaskDelay(1);
}
