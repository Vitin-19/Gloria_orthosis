#pragma once

#include <Arduino.h>
#include <ESP32Servo.h>

class Joint{
    private:
        int pin;
        int angle = 0;
        Servo servo;
    public:
        void setPin(int pin);
        int getPin();
        
        void attach();

        void setAngle(int angle);
        int getAngle();
        
};