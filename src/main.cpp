#include <Arduino.h>
#include "./controller/LoadCellController.h"
#include "./controller/JointsController.h"
#include "./controller/AccelerometerController.h"

LoadCellController lcController;
JointsController jController;
AccelerometerController aController;

float az;
float weight;

void setup() {
    Serial.begin(115200);

    jController.begin();
    jController.initialize();

    lcController.begin();

    aController.begin();
    
};

void loop() {
    delay(15);

    az = aController.getAz();
    weight = lcController.getWeight();

    if (az < 0.7 && weight < 1) {
        jController.getFood();
    }
    
    if (az > 0.85 && weight > 5) {
        jController.eat();
    }    
};