#include "AccelerometerController.h"

void AccelerometerController::begin(){
    sensor.initialize();

    view.showAccelerometerConnection(sensor.testConnection());
};

float AccelerometerController::getAz(){
    float az = sensor.readAz();

    model.setAz(az);

    view.showAz(model.getAz());
    
    return model.getAz();
};