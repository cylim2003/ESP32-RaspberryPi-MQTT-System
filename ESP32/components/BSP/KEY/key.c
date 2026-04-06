
#include "key.h"
#include "driver/gpio.h"
#include "esp_attr.h"
#include "LED.h"
#include "esp_log.h"
#include "freertos/idf_additions.h"
#include "hal/gpio_types.h"
#include <sys/types.h>
#include "freertos/FreeRTOS.h"
#include "freertos/idf_additions.h"
#include "freertos/task.h"

QueueHandle_t key_queue;

void IRAM_ATTR key_func(void *arg){
    uint32_t gpio_num = (uint32_t) arg;
    static u_int32_t x = 0;
    static u_int32_t keysend =1;
    if (gpio_num == 0) {
        xQueueSendFromISR(key_queue, &keysend,NULL);
    }

}


void key_init(void){
    key_queue = xQueueCreate(5,sizeof(int32_t));
    gpio_config_t key = {0};
    key.intr_type = GPIO_INTR_NEGEDGE;
    key.mode = GPIO_MODE_INPUT;
    key.pull_up_en = GPIO_PULLUP_ENABLE;
    key.pull_down_en = GPIO_PULLDOWN_DISABLE;
    key.pin_bit_mask = 1ULL<< KEY_GPIO_PIN;

    gpio_config(&key);

    gpio_install_isr_service(0);

    gpio_isr_handler_add(0,key_func,0);
    
    
}

