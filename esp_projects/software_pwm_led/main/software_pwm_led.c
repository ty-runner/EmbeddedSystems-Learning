#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "soc/gpio_struct.h"
#include "soc/gpio_reg.h"

#define LED_GPIO GPIO_NUM_2  // onboard LED on most ESP32 dev boards
#define LED_ON()   (GPIO.out_w1ts = (1 << LED_GPIO))
#define LED_OFF()  (GPIO.out_w1tc = (1 << LED_GPIO))
#define LED_TOGGLE() GPIO.out ^= (1 << LED_GPIO); 
/*void app_main(void) {
    // Configure LED pin
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    int period = 5;
    int duty_cycle = 1000;
    int max_duty = 255;
    int duty_delay = (duty_cycle * period) / max_duty;
    int off_delay = period - duty_delay;
    while (1) {
        LED_ON();
        vTaskDelay(duty_delay);
        LED_OFF();
        vTaskDelay(off_delay);
    }
}*/
void app_main(void) {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    const int period = 20;     // total PWM cycle in ms
    const int max_duty = 100;  // resolution
    //frequency
    //period
    while (1) {
        // Fade in
        for (int duty = 0; duty <= max_duty; duty++) {
            int duty_delay = (duty * period) / max_duty;
            int off_delay = period - duty_delay;
            // Clamp to at least 1 tick
            if (duty_delay < 1) duty_delay = 1;
            if (off_delay < 1) off_delay = 1;

            LED_ON();
            vTaskDelay(pdMS_TO_TICKS(duty_delay));
            LED_OFF();
            vTaskDelay(pdMS_TO_TICKS(off_delay));
        }

        // Fade out
        for (int duty = max_duty; duty >= 0; duty--) {
            int duty_delay = (duty * period) / max_duty;
            int off_delay = period - duty_delay;
            if (duty_delay < 1) duty_delay = 1;
            if (off_delay < 1) off_delay = 1;

            LED_ON();
            vTaskDelay(pdMS_TO_TICKS(duty_delay));
            LED_OFF();
            vTaskDelay(pdMS_TO_TICKS(off_delay));
        }
    }
}
/*void app_main(void) {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    int period = 5;       // total PWM cycle in ms
    int max_duty = 255;   // resolution

    while (1) {
        // Fade in
        for (int duty = 0; duty <= max_duty; duty++) {
            int duty_delay = (duty * period) / max_duty;
            int off_delay = period - duty_delay;

            LED_ON();
            vTaskDelay(pdMS_TO_TICKS(duty_delay));
            LED_OFF();
            vTaskDelay(pdMS_TO_TICKS(off_delay));
        }

        // Fade out
        for (int duty = max_duty; duty >= 0; duty--) {
            int duty_delay = (duty * period) / max_duty;
            int off_delay = period - duty_delay;

            LED_ON();
            vTaskDelay(pdMS_TO_TICKS(duty_delay));
            LED_OFF();
            vTaskDelay(pdMS_TO_TICKS(off_delay));
        }
    }
}
*/
