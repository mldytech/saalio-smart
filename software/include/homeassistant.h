#ifndef HOMEASSISTANT_H
#define HOMEASSISTANT_H

#include "config.h"
#include "mqtt.h"

void send_discovery_message();
void update_switch_state(const char *state);

#endif