#pragma once

#include "../sensor/AccelerometerSensor.h"

class SerialView{
    private:
        AccelerometerSensor as;

    public:
        void showWeight(float weight);
        void isAccelerometerConnected();
        void showAz(float az);   
};