#include <Bluepad32.h>

#include "ModeCar.h"
#include "ModeSelector.h"
#include "ModeTriggers.h"
#include "ModeWarthog.h"
#include "Motor.h"
#include "Router.h"

// compatabilty mode pinout
byte D10 = 21;
byte D9 = 18;
byte D8 = 17;

byte D5 = 8;
byte D4 = 7;
byte D3 = 6;


// objects
bool Motor :: log = true;
Router router(new Motor('A', D10, D9, D8), new Motor('B', D3, D5, D4));

ControllerPtr controller;

Modes modes {
  new ModeCar(controller, router),
  new ModeTriggers(controller, router),
  new ModeWarthog(controller, router)
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
