#pragma once

#include "../model/LoadCellModel.h"
#include "../sensor/LoadCellSensor.h"
#include "../view/SerialView.h"

class LoadCellController{
    private:
        LoadCellModel model;
        LoadCellSensor sensor;
        SerialView view;
    
    public:
        void begin();

        float getWeight();
};