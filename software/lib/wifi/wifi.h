#ifndef WIFI_H
#define WIFI_H

#include "esp_wifi.h"
#include "lwip/err.h"
#include "lwip/sys.h"

#include "config.h"

#define WIFI_MAX_RETRY 5
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1

extern int wifi_retry_num;
static EventGroupHandle_t s_wifi_event_group;

void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
void wifi_init_sta(void);

#endif