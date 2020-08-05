#ifndef ILERT_MQTT_H
#define ILERT_MQTT_H

#include <Arduino.h>

class ILERTMqtt {

    public:
        ~ILERTMqtt();
        String getHeartbeatMessage(String apiKey);
        String getEventMessage(
                                String apiKey,
                                String eventType,
                                String summary,
                                String incidentKey,
                                String details,
                                String customDetails,
                                String priority,
                                String linkUrl,
                                String imageUrl);
        String getDefaultHeartbeatTopic();
        String getDefaultEventTopic();
};

#endif /* ILERT_MQTT_H */
