#include "ILERTMqtt.h"

ILERTMqtt::~ILERTMqtt() {}

String ILERTMqtt::getHeartbeatMessage(String apiKey) {
    
    String message;

    message += F("{ \"apiKey\": \"");
    message += apiKey;
    message += F("\" }");

    return message;
}

String ILERTMqtt::getEventMessage(String apiKey,
                                  String eventType,
                                  String summary,
                                  String incidentKey,
                                  String details,
                                  String customDetails,
                                  String priority,
                                  String linkUrl,
                                  String imageUrl) {
    
    String message;

    message += F("{");

    message += F(" \"apiKey\": \"");
    message += apiKey;
    message += F("\"");
    message += F(",");

    if(eventType.length() <= 0) {
        eventType = String("ALERT");
    }

    message += F(" \"eventType\": \"");
    message += eventType;
    message += F("\"");
    message += F(",");

    if(incidentKey.length() > 0) {
        message += F(" \"incidentKey\": \"");
        message += incidentKey;
        message += F("\"");
        message += F(",");
    }

    if(details.length() > 0) {
        message += F(" \"details\": \"");
        message += details;
        message += F("\"");
        message += F(",");
    }

    if(customDetails.length() > 0) {
        message += F(" \"customDetails\": \"");
        message += customDetails;
        message += F("\"");
        message += F(",");
    }

    if(linkUrl.length() > 0) {
        message += F(" \"links\": [{ \"text\": \"Link\", \"href\": \"");
        message += linkUrl;
        message += F("\" }]");
        message += F(",");
    }

    if(imageUrl.length() > 0) {
        message += F(" \"images\": [{ \"src\": \"");
        message += imageUrl;
        message += F("\" }]");
        message += F(",");
    }

    if(priority.length() <= 0) {
        priority = String("HIGH");
    }

    message += F(" \"priority\": \"");
    message += priority;
    message += F("\"");
    message += F(",");

    message += F(" \"summary\": \"");
    message += summary;
    message += F("\"");

    message += F(" }");

    return message;
}

String ILERTMqtt::getDefaultHeartbeatTopic() {
    return String("ilert/heartbeats");
}

String ILERTMqtt::getDefaultEventTopic() {
    return String("ilert/events");
}
