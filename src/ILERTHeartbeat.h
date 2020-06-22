#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

#ifndef ILERT_HEARTBEAT_H
#define ILERT_HEARTBEAT_H

class ILERTHeartbeat {

    private:
        const char *apiKey = nullptr;
        unsigned long lastMillis = 0;
        unsigned int intervalSec = 60;

    public:
        ~ILERTHeartbeat();
        void begin(const char _apiKey[], unsigned int intervalSec);
        void setApiKey(const char _apiKey[]);
        bool loop();
        bool sendHeartbeat();
};

#endif
