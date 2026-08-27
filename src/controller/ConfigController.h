#ifdef CONFIG_CONTROLLER_H
#define CONFIG_CONTROLLER_H

#include <Arduino.h>
#include <Preferences.h>
#include "./model/ConfigModel.h"

class ConfigController {
private:
    Preferences preferences;
public:
    bool begin();

    WifiConfig getWifiConfig();
    MQTTConfig getMQTTConfig();

    void saveWifiConfig(const String& ssid, const String& password);
    void saveMQTTConfig(const String& host, int port, const String& username, const String& password);
    void config();

    bool hasWifiConfig();
}

#endif