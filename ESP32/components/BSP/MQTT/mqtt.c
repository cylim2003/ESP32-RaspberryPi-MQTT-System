#include "mqtt.h"
#include "freertos/idf_additions.h"

QueueHandle_t mqtt_queue;

static const char *TAG_MQTT = "mqtt";
esp_mqtt_client_handle_t client;
static void mqtt_event_handler(void *handler_args, esp_event_base_t base,
                               int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;

    switch ((esp_mqtt_event_id_t)event_id) {

        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG_MQTT, "MQTT connected");

            esp_mqtt_client_subscribe(event->client, "enter/topicB", 0);

            esp_mqtt_client_publish(event->client, "enter/topicA", "1", 0, 0, 0);
            break;

        case MQTT_EVENT_DATA:
            ESP_LOGI(TAG_MQTT, "Received: %.*s", event->data_len, event->data);
            char msg[50];
            memcpy (msg,event->data,event->data_len);
            msg[event->data_len] = '\0';
            xQueueSend(mqtt_queue,msg,10);
            break;

        default:
            break;
    }
}


void mqtt_app_start(void)
{
    mqtt_queue = xQueueCreate(5, sizeof(char[50]));
    esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = "mqtt://0.tcp.jp.ngrok.io:12345", //enter broker addr 
    };

    client = esp_mqtt_client_init(&mqtt_cfg);

    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);

    esp_mqtt_client_start(client);
    
}

void mqtt_publish(const char*topic,const char*msg){
    if(client != NULL){
        esp_mqtt_client_publish(client, topic, msg, 0, 0, 0);
    }
}
