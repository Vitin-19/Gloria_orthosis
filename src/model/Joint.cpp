#include "Joint.h"

int Joint::getPin(){
    return this->pin;
}

void Joint::setPin(int pin){
    this->pin = pin;
}

void Joint::attach(){
    servo.attach(getPin());
}

int Joint::getAngle(){
    return this->angle;
}

void Joint::setAngle(int angle){
    this->angle = angle;

    servo.write(getAngle());
}