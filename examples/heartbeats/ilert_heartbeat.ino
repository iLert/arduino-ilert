/*
 Basic Heartbeat example
 This sketch demonstrates the basic capabilities of the library.
 It creates a heartbeat then:
  - configures it with apiKey and interval
  - automatically pings the heartbeat resource, when invoked in loop
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <ILERT.h>

const char SSID[] = "my-wifi-ssid";
const char WIFI_PASS[] = "my-wifi-password";
WiFiClient net;

// create a new heartbeat instance (you can create multiple if you like)
ILERTHeartbeat heartbeat;

void connect();

void setup() {

    // configure heartbeat
    unsigned int heartbeatIntervalSec = 60;
    heartbeat.begin("your-heartbeat-integration-key", heartbeatIntervalSec);
}

void loop() {
    connect();
    delay(100);

    // update heartbeat in loop
    heartbeat.loop();
}

/*
    just the basic wifi setup
    an internet connection is required
    to access iLert's API
*/
void connect() {  
    delay(10);

    if(WiFi.status() == WL_CONNECTED) {
        return;
    }

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
}
