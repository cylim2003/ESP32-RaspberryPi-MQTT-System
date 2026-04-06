#ifndef __KEY_H_
#define __KEY_H_

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/idf_additions.h"
#include "freertos/task.h"

#define KEY_GPIO_PIN   GPIO_NUM_0

// #define BOOT gpio_get_level(BOOT_INT_GPIO_PIN)
extern QueueHandle_t key_queue;
void key_init(void);

#endif
// #ifndef __KEY_H_
// #define __KEY_H_

// #include "driver/gpio.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"

// #define BOOT_GPIO_PIN GPIO_NUM_0
// #define BOOT_PRESS 1
// #define BOOT gpio_get_level(BOOT_GPIO_PIN)

// void key_init(void);
// uint8_t key_scan(uint8_t mode);


// #endif