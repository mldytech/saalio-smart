#include "homeassistant.h"

void send_discovery_message() {
    const char *discovery_topic = "homeassistant/switch/saalio/config";
    const char *discovery_payload = "{\"name\": \"saalio\", \"state_topic\": \"home/saalio/state\", \"command_topic\": \"home/saalio/set\", \"payload_on\": \"ON\", \"payload_off\": \"OFF\"}";

    int msg_id = esp_mqtt_client_publish(client, discovery_topic, discovery_payload, 0, 1, 0);
    ESP_LOGI(TAG, "Discovery message sent, msg_id=%d", msg_id);
}

void update_switch_state(const char *state) {
    const char *state_topic = "home/saalio/state";
    int msg_id = esp_mqtt_client_publish(client, state_topic, state, 0, 1, 0);
    ESP_LOGI(TAG, "Switch state updated, msg_id=%d", msg_id);
}