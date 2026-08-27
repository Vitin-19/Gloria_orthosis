#pragma once
#include "ConfigController.h"
#include <Arduino.h>
#include <Wifi.h>

bool ConfigController::begin() {
    return true;
}

void ConfigController::saveWifiConfig(const String& ssid, const String& password) {
    preferences.begin("wifi", false);

    preferences.putString("ssid", ssid);
    preferences.putString("password", password);

    preferences.end();
}

void ConfigController::saveMQTTConfig(const String& host, int port, const String& username, const String& password) {
    preferences.begin("mqtt", false);

    preferences.putString("host", host);
    preferences.putInt("port", port);
    preferences.putString("username", username);
    preferences.putString("password", password);

    preferences.end();
}

WifiConfig ConfigController::getWifiConfig() {
    preferences.begin("wifi", true);

    WifiConfig config;
    config.ssid = preferences.getString("ssid", "");
    config.password = preferences.getString("password", "");

    preferences.end();
    return config;
}

MQTTConfig ConfigController::getMQTTConfig() {
    preferences.begin("mqtt", true);

    MQTTConfig config;
    config.host = preferences.getString("host", "");
    config.port = preferences.getInt("port", 1883);
    config.username = preferences.getString("username", "");
    config.password = preferences.getString("password", "");

    preferences.end();
    return config;
}

bool ConfigController::hasWifiConfig() {

    preferences.begin("wifi", true);

    String ssid = preferences.getString("ssid", "");
    String password = preferences.getString("password", "");

    preferences.end();

    return !ssid.isEmpty() && !password.isEmpty();
}

void ConfigController::config() {
    if(hasWifiConfig()) {
        WifiConfig wifiConfig = getWifiConfig();
        MQTTConfig mqttConfig = getMQTTConfig();

        Serial.println("WiFi Config:");
        Serial.println("SSID: " + wifiConfig.ssid);
        Serial.println("Password: " + wifiConfig.password);

        Serial.println("MQTT Config:");
        Serial.println("Host: " + mqttConfig.host);
        Serial.println("Port: " + String(mqttConfig.port));
        Serial.println("Username: " + mqttConfig.username);
        Serial.println("Password: " + mqttConfig.password);

        
    } else {
        Serial.println("No WiFi configuration found.");
    }
}