#include "AccelerometerController.h"

void AccelerometerController::begin(){
    sensor.initialize();

    view.showAccelerometerConnection(sensor.testConnection());

    model.setBaseline(sensor.calibrateSensor());
};

float AccelerometerController::getAz(){
    float az = sensor.readAz();

    model.setAz(az);

    view.showAz(model.getAz() - model.getBaseline());
    
    return model.getAz();
};

float AccelerometerController::getBaseline(){
    return model.getBaseline();
};