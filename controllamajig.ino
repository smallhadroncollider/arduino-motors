#include <Bluepad32.h>

#include "ModeCar.h"
#include "ModeTriggers.h"
#include "Motor.h"
#include "Router.h"

// compatabilty mode pinout
byte D10 = 21;
byte D9 = 18;
byte D8 = 17;

byte D3 = 6;
byte D5 = 8;
byte D4 = 7;

// objects
Motor motorA(D10, D9, D8);
Motor motorB(D3, D5, D4);
Router router(motorA, motorB);

ControllerPtr controller;

ModeCar modeCar(controller, router);
ModeTriggers modeTriggers(controller, router);

Mode &modePtr = modeCar;

void setup() {
  Serial.begin(115200);

  motorA.setup();
  motorB.setup();
  BP32.setup(&onConnectedController, &onDisconnectedController);

  Serial.println("Waiting for controller to connect");
}

void loop() {
  if (BP32.update() && controller && controller->isConnected() && controller->hasData()) {
    if (controller->y() || controller->a()) {
      modePtr = modeCar;
    }

    if (controller->b()) {
      modePtr = modeTriggers;
    }

    modePtr.update();
  }

  vTaskDelay(1);
}
