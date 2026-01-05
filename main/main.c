#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include <sys/time.h>

//A function to specify delays in milliseconds
void delay_ms(int t) {
    vTaskDelay(t /portTICK_PERIOD_MS);
}
#define LED_GPIO GPIO_NUM_10
#define BUTTON GPIO_NUM_4

void app_main(void)
{
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_reset_pin(BUTTON);
    gpio_set_direction(BUTTON, GPIO_MODE_INPUT);
    gpio_set_level(LED_GPIO, 0);
   
   while (1) {
      if (gpio_get_level(BUTTON)) {
        gpio_set_level(LED_GPIO, 1);
      }
    else {
        gpio_set_level(LED_GPIO, 0);
        delay_ms(500);
      }
    delay_ms(100);
   }
}
