void onConnectedController(ControllerPtr ctl) {
  Serial.println("Controller connected");
  controller = ctl;
}

void onDisconnectedController(ControllerPtr ctl) {
  Serial.println("Controller disconnected");
  controller = nullptr;
}
