#include "LED.h"
#include "driver/gpio.h"

void led_init(void){
    gpio_config_t gpio_led = {0};
    gpio_led.mode = GPIO_MODE_OUTPUT;
    gpio_led.intr_type = GPIO_INTR_DISABLE;
    gpio_led.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_led.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_led.pin_bit_mask = 1ULL << LED_GPIO_PIN;

     gpio_config(&gpio_led);

}

void led_set(uint32_t set){
    gpio_set_level(LED_GPIO_PIN, set);
}