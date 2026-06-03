#pragma once

class AccelerometerModel{
    private:
        float az = 0;
        float baseline = 0.0;
    public:
        float getAz();
        void setAz(float az);

        float getBaseline();
        void setBaseline(float baseline);
};