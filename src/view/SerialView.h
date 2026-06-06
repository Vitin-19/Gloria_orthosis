#pragma once


class SerialView{
    public:
        static void beginWebSerial(
            const char* ssid = "Gloria-Orthosis",
            const char* password = "gloria123"
        );

        void showWeight(float weight);
        void showAccelerometerConnection(bool connected);
        void showAz(float az);   
};
