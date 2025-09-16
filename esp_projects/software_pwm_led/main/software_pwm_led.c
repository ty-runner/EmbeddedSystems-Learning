#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"

#include "freertos/task.h"
#include "driver/gpio.h"
#include "soc/gpio_struct.h"
#include "soc/gpio_reg.h"

#define LED_GPIO GPIO_NUM_2  // onboard LED on most ESP32 dev boards
#define LED_ON()   (GPIO.out_w1ts = (1 << LED_GPIO))
#define LED_OFF()  (GPIO.out_w1tc = (1 << LED_GPIO))
#define LED_TOGGLE() GPIO.out ^= (1 << LED_GPIO); 

void pwm_init() {
    // Configure the timer
    ledc_timer_config_t timer = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_10_BIT, // 0–1023 steps
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 1000, // 1 kHz PWM (period = 1 ms)
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&timer);

    // Configure the channel
    ledc_channel_config_t channel = {
        .gpio_num   = LED_GPIO,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel    = LEDC_CHANNEL_0,
        .intr_type  = LEDC_INTR_DISABLE,
        .timer_sel  = LEDC_TIMER_0,
        .duty       = 0,
        .hpoint     = 0
    };
    ledc_channel_config(&channel);
}
void fade_task(void *pvParameter) {
    int duty = 0;
    int step = 10; // adjust for smoothness (0–1023 range)

    while (1) {
        // Update PWM duty
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, duty);
        ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);

        duty += step;
        if (duty >= 1023) { 
            duty = 1023;
            step = -step; 
        } else if (duty <= 0) { 
            duty = 0;
            step = -step; 
        }

        vTaskDelay(pdMS_TO_TICKS(10)); // controls fade speed
    }
}

void app_main(void) {
    pwm_init();
    xTaskCreate(fade_task, "fade_task", 2048, NULL, 5, NULL);
}

