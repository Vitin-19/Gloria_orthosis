#pragma once
#include "../model/MqttConfig.h"
#include <Arduino.h>

class MqttController {
public:
    MqttController(MqttConfig* config);
    void begin();
    void update();
    void onMessageReceived(const char* topic, const char* payload);
    void sendMessage(const char* topic, const char* payload);
    MqttConfig* getConfig();

private:
    MqttConfig* config;
    void handleMessage(const char* topic, const char* payload);
};