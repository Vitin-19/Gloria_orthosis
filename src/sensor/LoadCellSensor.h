#pragma once

#include <HX711.h>

class LoadCellSensor{
private:
    HX711 loadCell;

    static constexpr int DT = 4;
    static constexpr int SCK = 5;

    static constexpr float scale = 420.5;
public:
    void begin();
    
    float readWeight();

};

