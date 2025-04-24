#ifndef INFLUX_H
#define INFLUX_H

#include "esp_http_client.h"

#include "config.h"
void send_influx_keepalive(void *pvParameters);

#endif