#include "LoadCellController.h"

void LoadCellController::begin(){
    sensor.begin();
}

float LoadCellController::getWeight(){
    float weight = sensor.readWeight();

    model.setWeight(weight);

    view.showWeight(model.getWeight());

    return model.getWeight();
};