#ifndef __MQTT_H_
#define __MQTT_H_

#include "mqtt5_client.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/idf_additions.h"
#include "freertos/task.h"

extern QueueHandle_t mqtt_queue;

void mqtt_app_start(void);

void mqtt_publish(const char*topic,const char*msg);


#endif