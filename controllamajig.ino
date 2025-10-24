#include <Bluepad32.h>

#include "ModeCar.h"
#include "ModeSelector.h"
#include "ModeTriggers.h"
#include "ModeWarthog.h"
#include "MotorDriverDRV8833.h"
#include "Motor.h"
#include "Router.h"

// compatabilty mode pinout
byte D9 = 9;
byte D8 = 8;

byte D5 = 7;
byte D4 = 6;


// objects
bool Motor :: log = true;

MotorDriverDRV8833 motorA(D9, D8);
MotorDriverDRV8833 motorB(D4, D5);
Router router(new Motor('A', motorA), new Motor('B', motorB));

ControllerPtr controller;

Modes modes {
  new ModeCar(controller, router),
  new ModeTriggers(controller, router),
  new ModeWarthog(controller, router)
};

ModeSelector modeSelector(controller, modes);

void setup() {
  Serial.begin(115200);

  motorA.setup();
  motorB.setup();
  BP32.setup(&onConnectedController, &onDisconnectedController);

  Serial.println("Waiting for controller to connect");
}

void loop() {
  if (BP32.update() && controller && controller->isConnected() && controller->hasData()) {
    if (controller->a()) {
      router.reset();
      modeSelector.reset();
      Serial.println("Reset config");
    }

    router.handleFlip(controller);
    modeSelector.update();
  }

  vTaskDelay(1);
}
