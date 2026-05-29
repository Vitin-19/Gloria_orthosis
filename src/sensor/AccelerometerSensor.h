#pragma once
#include <MPU6050.h>

class AccelerometerSensor {
    private:
        MPU6050 accelerometer;

    public:
        void initialize();
        float readAz();
        bool testConnection();
        float convertAcceleration(int16_t a);
};