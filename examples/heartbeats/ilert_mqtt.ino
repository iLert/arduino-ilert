#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <MQTT.h>
#include <ILERT.h>

// your ilagent mqtt host https://github.com/iLert/ilagent
const char MQTT_SERVER[] = "192.168.1.14";
const int MQTT_SERVER_PORT = 1883;
const char MQTT_CLIENT_NAME[] = "example-name";
MQTTClient client(1024); // depending on the message payload size that you are sending you will have to increase the buffer

const char SSID[] = "my-wifi-ssid";
const char WIFI_HOST[] = "example-host";
const char WIFI_PASS[] = "my-wifi-password";
WiFiClient net;

ILERTMqtt ilertMqtt;
unsigned long lastMillis = 0;

void connect();

/**
 * invoked every 30 seconds
 * if WiFi and MQTT clients are connected
 */
void logicLoop() {

    // proxy heartbeat through mqtt to iLert
    String heartbeatMessage = ilertMqtt.getHeartbeatMessage("your-heartbeat-integration-key");
    client.publish(ilertMqtt.getDefaultHeartbeatTopic(), heartbeatMessage);

    // proxy event through mqtt to iLert
    String eventMessage = ilertMqtt.getEventMessage(
        "your-alertsource-integration-key",
        "ALERT",
        "a summary",
        "key123", // optional
        "some optional details", // optional
        "{}", // custom details, optional
        "", // priority, defaults to HIGH
        "https://www.ilert.com/...", // linkUrl, optional
        "https://www.ilert.com/...png" // imageUrl, optional
    );
    client.publish(ilertMqtt.getDefaultEventTopic(), eventMessage);
}

void setup() {
    Serial.begin(115200);
    WiFi.hostname(WIFI_HOST);
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, WIFI_PASS);
    client.begin(MQTT_SERVER, MQTT_SERVER_PORT, net);
    connect();
}

void loop() {

    client.loop();
    delay(100); // WiFi stability

    if (!client.connected()) {
        connect();
    }

    if (millis() - lastMillis > 30000) {
        lastMillis = millis();
        logicLoop();
    }
}

/**
 * just the basic wifi and mqtt client setup
*/
void connect() {  
    delay(10);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    while (!client.connect(MQTT_CLIENT_NAME)){
        delay(1000);
    }
}
