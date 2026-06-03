#include "./AccelerometerModel.h"

float AccelerometerModel::getAz(){
    return this->az;
}

void AccelerometerModel::setAz(float az){
    this->az = az;
}

float AccelerometerModel::getBaseline(){
    return this->baseline;
}

void AccelerometerModel::setBaseline(float baseline){
    this->baseline = baseline;
}