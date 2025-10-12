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
bool Router :: log = true;
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
    if (controller->a()) {
      router.reset();
      modeSelector.reset();
      Serial.println("Reset config");
    }

    router.handleFlip(controller);
    modeSelector.update();

/*
    char buf[256];
    snprintf(buf, sizeof(buf) - 1,
            "idx=%d, dpad: 0x%02x, buttons: 0x%04x, "
            "axis L: %4li, %4li, axis R: %4li, %4li, "
            "brake: %4ld, throttle: %4li, misc: 0x%02x, "
            "gyro x:%6d y:%6d z:%6d, accel x:%6d y:%6d z:%6d, "
            "battery: %d",
            controller->index(),        // controller Index
            controller->dpad(),         // DPad
            controller->buttons(),      // bitmask of pressed buttons
            controller->axisX(),        // (-511 - 512) left X Axis
            controller->axisY(),        // (-511 - 512) left Y axis
            controller->axisRX(),       // (-511 - 512) right X axis
            controller->axisRY(),       // (-511 - 512) right Y axis
            controller->brake(),        // (0 - 1023): brake button
            controller->throttle(),     // (0 - 1023): throttle (AKA gas) button
            controller->miscButtons(),  // bitmask of pressed "misc" buttons
            controller->gyroX(),        // Gyro X
            controller->gyroY(),        // Gyro Y
            controller->gyroZ(),        // Gyro Z
            controller->accelX(),       // Accelerometer X
            controller->accelY(),       // Accelerometer Y
            controller->accelZ(),       // Accelerometer Z
            controller->battery()       // 0=Unknown, 1=empty, 255=full
    );
    Serial.println(buf);
    */
  }

  vTaskDelay(1);
}
