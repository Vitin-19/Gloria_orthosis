#include "LoadCellSensor.h"
#include <cmath>

void LoadCellSensor::begin(){
    loadCell.begin(DT, SCK);

    loadCell.set_scale(scale);

    loadCell.tare();
};

float LoadCellSensor::readWeight(){
    return abs(loadCell.get_units(10)) - averageFood;
};