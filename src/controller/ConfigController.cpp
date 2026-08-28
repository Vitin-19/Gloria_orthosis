#pragma once
#include "ConfigController.h"
#include "../model/ConfigModel.h"
#include <Arduino.h>
#include <Wifi.h>

bool ConfigController::begin() {
    mqttClient.setClient(wifiClient);
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

bool ConfigController::connectWifi(){
    if(!hasWifiConfig()){
        Serial.println("No WiFi config found.");

        // Implement accesspoint logic here

        return false;
    }

    WifiConfig wifiConfig = getWifiConfig();

    Serial.print("Connecting to WiFi: ");
    Serial.println(wifiConfig.ssid);

    WiFi.begin(wifiConfig.ssid.c_str(), wifiConfig.password.c_str());

    for(int i = 0; i < 20 && Wifi.status() != WL_CONNECTED; i++){
        delay(500);
        Serial.print(".");
    }

    if(WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi connected.");
        return true;
    } else {
        Serial.println("\nFailed to connect to WiFi.");

        // implement accesspoint logic here

        return false;
    }
}

bool ConfigController::connectMQTT() {
    MqttConfig mqttConfig = getMQTTConfig();

    if(config.host.isEmpty() || config.port == 0) {
        Serial.println("No MQTT config found.");
        return false;
    }

    mqttClient.setServer(mqttConfig.host.c_str(), mqttConfig.port);

    if(config.username.isEmpty() || config.password.isEmpty()) {
        Serial.println("Missing authentication details for MQTT.");
        return false;
    }

    if(mqttClient.connect("01", config.username.c_str(), config.password.c_str())) {
        Serial.println("Connected to MQTT broker.");
        return true;
    } else {
        Serial.print("Failed to connect to MQTT broker. State: ");
        Serial.println(mqttClient.state());
        return false;

    }
}