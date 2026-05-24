#include <Arduino.h>
#include "./controller/LoadCellController.h"

LoadCellController lcController;


void setup() {
    Serial.begin(115200);

    lcController.begin();
};

void loop() {
   lcController.update();

   delay(3000);
};
