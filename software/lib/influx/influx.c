#include "influx.h"

void send_influx_keepalive(void *pvParameters) {
    while (1) {
        const char *payload = "keepalive,host=saalio value=1";

        esp_http_client_config_t config = {
            .url = INFLUXDB_URL,
            .method = HTTP_METHOD_POST,
            .username = INFLUX_USER,
            .password = INFLUX_PW,
            .auth_type = HTTP_AUTH_TYPE_BASIC,
        };

        esp_http_client_handle_t client = esp_http_client_init(&config);
        esp_http_client_set_post_field(client, payload, strlen(payload));

        esp_err_t err = esp_http_client_perform(client);
        if (err == ESP_OK) {
            int status_code = esp_http_client_get_status_code(client);
            ESP_LOGI(TAG, "Sent keepalive, HTTP Status Code: %d\n", status_code);
        } else {
            ESP_LOGE(TAG, "Error while sending keepalive: %s\n", esp_err_to_name(err));
        }

        esp_http_client_cleanup(client);

        vTaskDelay(pdMS_TO_TICKS(10000)); //10sec
    }
}