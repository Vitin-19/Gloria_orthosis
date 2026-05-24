#pragma once

#include "../model/LoadCellModel.h"
#include "../sensor/LoadCellSensor.h"
#include "../view/SerialView.h"

class LoadCellController{
    private:
        LoadCellModel model;
        LoadCellSensor sensor;
        SerialView view;

        static constexpr float FOOD_LIMIT = 20.0;
    
    public:
        void begin();

        void update();
};