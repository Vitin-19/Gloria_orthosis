#include <Arduino.h>
#include "./controller/LoadCellController.h"
#include "./controller/JointsController.h"
#include "./controller/AccelerometerController.h"

LoadCellController lcController;
JointsController jController;
AccelerometerController aController;

float az;
float weight;
bool gettingFood = false;
bool eating = false;
bool lastGettingFood = false;
bool lastEating = false;

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
        gettingFood = true;
        eating = false;
    }

    if (az > 0.85 && weight > 5) {
        gettingFood = false;
        eating = true;
    }

    if (gettingFood && !lastGettingFood) {
        jController.getFood();
    }

    if (eating && !lastEating) {
        jController.eat();
    }

    lastGettingFood = gettingFood;
    lastEating = eating;
}