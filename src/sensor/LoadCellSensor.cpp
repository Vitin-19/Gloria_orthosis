#include "LoadCellSensor.h"

void LoadCellSensor::begin(){
    loadCell.begin(DT, SCK);

    loadCell.set_scale(scale);

    loadCell.tare();
}

float LoadCellSensor::readWeight(){
    return loadCell.get_units(10);
}