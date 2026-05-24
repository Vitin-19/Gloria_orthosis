#include "LoadCellController.h"

void LoadCellController::begin(){
    sensor.begin();
}

void LoadCellController::update(){
    float weight = sensor.readWeight();

    model.setWeight(weight);

    view.showWeight(model.getWeight());
};