#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "esp_event.h"
#include "nvs_flash.h" //non volatile storage

#include "config.h"
#include "wifi.h"
#include "mqtt.h"
#include "influx.h"
#include "homeassistant.h"


void app_main(void)
{
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    
    wifi_init_sta();                        //initialize WiFi

    #ifdef SEND_TO_HOMEASSISTANT
    mqtt_app_start();                       //connect to mqtt broker

    //say hello to hass
    esp_mqtt_client_publish(client, "/saalio/keepalive", "Hello World", 0, 1, 0);
    send_discovery_message();
    update_switch_state("ON");
    #endif

    #ifdef SEND_TO_INFLUX
    //start a parallel task for sending the keepalive message to influxdb

    xTaskCreate(send_influx_keepalive, "send_keepalive", 2048, NULL, 5, NULL);
    #endif

    fflush(stdout);
}