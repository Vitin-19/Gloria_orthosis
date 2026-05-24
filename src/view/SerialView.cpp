#include "SerialView.h"
#include <Arduino.h>

void SerialView::showWeight(float weight){
    Serial.print("Weight: ");
    Serial.print(weight);
    Serial.println("g");
};