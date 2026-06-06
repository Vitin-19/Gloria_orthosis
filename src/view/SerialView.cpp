#include "SerialView.h"
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

namespace {
    AsyncWebServer server(80);
    bool webSerialStarted = false;

    void writeLine(const String& message){
        Serial.println(message);

        if(webSerialStarted){
            WebSerial.println(message);
        }
    }

    void receiveMessage(uint8_t* data, size_t len){
        String message;

        for(size_t i = 0; i < len; i++){
            message += static_cast<char>(data[i]);
        }

        Serial.print("[WebSerial] ");
        Serial.println(message);
    }
}

void SerialView::beginWebSerial(const char* ssid, const char* password){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);

    WebSerial.begin(&server);
    WebSerial.msgCallback(receiveMessage);

    server.begin();
    webSerialStarted = true;

    writeLine("WebSerial started");
    writeLine(String("WiFi network: ") + ssid);
    writeLine(String("Open: http://") + WiFi.softAPIP().toString() + "/webserial");
}

void SerialView::showWeight(float weight){
    writeLine(String("Weight: ") + String(weight) + "g");
};

void SerialView::showAccelerometerConnection(bool connected){
    if(connected){
        writeLine("Accelerometer connected successfully");
    }else{
        writeLine("Failed in connecting accelerometer");
    }
};

void SerialView::showAz(float az){
    writeLine(String("AZ: ") + String(az));
};
