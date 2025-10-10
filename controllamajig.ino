#include <Bluepad32.h>

#include "ModeCar.h"
#include "ModeSelector.h"
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
Router router(new Motor(D10, D9, D8), new Motor(D3, D5, D4));

ControllerPtr controller;

Modes modes {
  new ModeCar(controller, router),
  new ModeTriggers(controller, router)
};

ModeSelector modeSelector(controller, modes);

void setup() {
  Serial.begin(115200);

  router.setup();
  BP32.setup(&onConnectedController, &onDisconnectedController);

  Serial.println("Waiting for controller to connect");
}

void loop() {
  if (BP32.update() && controller && controller->isConnected() && controller->hasData()) {
    modeSelector.update();
  }

  vTaskDelay(1);
}
