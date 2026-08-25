#include "MqttConfig.h"

char* MqttConfig::getMqttPass() {
    return mqtt_pass;
}

char* MqttConfig::getMqttUser() {
    return mqtt_user;
}

char* MqttConfig::getMqttServer() {
    return mqtt_server;
}

char* MqttConfig::getPassword() {
    return password;
}

char* MqttConfig::getSSID() {
    return ssid;
}

