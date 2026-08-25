#pragma once

class MqttConfig{
    private:
        char* ssid;
        char* password;
        char* mqtt_server;
        char* mqtt_user;
        char* mqtt_pass;
    public:
        char* getSSID();
        char* getPassword();
        char* getMqttServer();
        char* getMqttUser();
        char* getMqttPass();
}