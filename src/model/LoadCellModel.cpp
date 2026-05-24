#include "LoadCellModel.h"
#include "HX711.h"

void LoadCellModel::setWeight(float newWeight){
    weight = newWeight;
};

float LoadCellModel::getWeight(){
    return weight;
};

