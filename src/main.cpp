#include <Arduino.h>
#include "./controller/LoadCellController.h"
#include "./controller/JointsController.h"

LoadCellController lcController;
JointsController jController;


void setup() {
    Serial.begin(115200);

    jController.begin();
    jController.initialize();
    // lcController.begin();
};

void loop() {
//    lcController.update();
    jController.getFood();
    delay(3000);
    jController.eat();
    delay(3000);
//    delay(3000);
};