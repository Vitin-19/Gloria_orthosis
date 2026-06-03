#include "./AccelerometerSensor.h"
#include <Wire.h>


void AccelerometerSensor::initialize(){
    Wire.begin();
    accelerometer.initialize();
};

float AccelerometerSensor::convertAcceleration(int16_t a){
    return a / 16384.0;
};

float AccelerometerSensor::readAz(){
    return convertAcceleration(accelerometer.getAccelerationZ());
};

bool AccelerometerSensor::testConnection(){
    return accelerometer.testConnection();
};

float AccelerometerSensor::calibrateSensor(){
    float sum = 0.0;

    for (int i = 0; i < 100; i++) {
        sum += readAz();
        delay(10);
    }

    return sum / 100;
};