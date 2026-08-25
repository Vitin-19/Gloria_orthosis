#include "MqttController.h"

MqttController::MqttController(MqttConfig* config) : config(config) {}

MqttConfig* MqttController::getConfig() {
    return config;
}

MqttController::begin() {
    // Initialize MQTT connection here using config parameters
}