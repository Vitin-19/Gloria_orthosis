#include "SerialView.h"
#include <Arduino.h>

void SerialView::showWeight(float weight){
    Serial.print("Weight: ");
    Serial.print(weight);
    Serial.println("g");
};

void SerialView::showAccelerometerConnection(bool connected){
    if(connected){
        Serial.println("Accelerometer connected successfully");
    }else{
        Serial.println("Failed in connecting accelerometer");
    }
};

void SerialView::showAz(float az){
    Serial.print("AZ: ");
    Serial.println(az);
};