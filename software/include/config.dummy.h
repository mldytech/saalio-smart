#ifndef SECRETS_H
#define SECRETS_H

#include "esp_log.h"

static const char *TAG = "saalio-smart";

#define SEND_TO_HOMEASSISTANT   1
#define SEND_TO_INFLUX          1

#define WIFI_SSID   "wifissid"
#define WIFI_PW     "wifipassword"

#define MQTT_ADDR "mqtt://mqttserver"
#define MQTT_USER "mqttusername"
#define MQTT_PW "mqttpassword"

#define INFLUXDB_URL "http://influxserver:8086/write?db=saalio" //line protocol
#define INFLUX_USER "influxuser"
#define INFLUX_PW "influxpassword"

#endif