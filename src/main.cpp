#include <Arduino.h>
#include "./controller/LoadCellController.h"
#include "./controller/JointsController.h"
#include "./controller/AccelerometerController.h"
#include "./model/OrthosisStates.h"

LoadCellController lcController;
JointsController jController;
AccelerometerController aController;

float baseline;
float movement;

float weight;

OrthosisStates state = OrthosisStates::IDLE;
OrthosisStates lastState = OrthosisStates::IDLE;

void setup() {
    Serial.begin(115200);

    jController.begin();
    jController.initialize();

    lcController.begin();

    aController.begin();

    baseline = aController.getBaseline();
  
};

void loop() {
    delay(20);

    movement = aController.getAz() - baseline;
    weight = lcController.getWeight();

    if (movement > 0.01 && weight < 1.0) {
        state = OrthosisStates::GETTINGFOOD;
    }else if (movement < -0.01 && weight > 5.0) {
        state = OrthosisStates::EATING;
    }

    if (state != lastState) {
        if (state == OrthosisStates::GETTINGFOOD) {
            jController.getFood();
        }

        if (state == OrthosisStates::EATING) {
            jController.eat();
        }

        lastState = state;
    }
}