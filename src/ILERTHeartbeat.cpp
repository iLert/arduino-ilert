#include "ILERTHeartbeat.h"

#ifndef ILERT_BASE
#define ILERT_BASE "https://api.ilert.com/api/v1"
#endif

bool ILERTHeartbeat::sendHeartbeat() {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    // only do this on heartbeats, never with sensitive data
    client->setInsecure();
    HTTPClient https;

    String url = "";
    url += ILERT_BASE;
    url += "/heartbeats/";
    url += this->apiKey;

    bool connected = https.begin(*client, url);
    if(!connected) {
        // Serial.println("Failed to connect via HTTPS.");
        return false;
    }

    https.setTimeout(23000);
    int httpResponseCode = https.GET();
    bool successfull = httpResponseCode == 202;
    /* if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.printf("Request failed: %s\n", https.errorToString(httpResponseCode).c_str());
    } */

    https.end();
    return successfull;
}

void ILERTHeartbeat::setApiKey(const char _apiKey[]) {

    if (this->apiKey != nullptr) {
        free((void *)this->apiKey);
    }

    this->apiKey = strdup(_apiKey);
}

ILERTHeartbeat::~ILERTHeartbeat() {
 
    if (this->apiKey != nullptr) {
        free((void *)this->apiKey);
    }
}

void ILERTHeartbeat::begin(const char _apiKey[], unsigned int intervalSec) {
    this->setApiKey(_apiKey);
    this->intervalSec = intervalSec;
}

bool ILERTHeartbeat::loop() {

     if (millis() - this->lastMillis > (this->intervalSec * 1000)) {
        this->lastMillis = millis();
        return this->sendHeartbeat();
    }

    return false;
}
