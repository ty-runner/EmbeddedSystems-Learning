#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "soc/gpio_struct.h"
#include "soc/gpio_reg.h"

#define LED_GPIO GPIO_NUM_2  // onboard LED on most ESP32 dev boards
#define BUTTON_GPIO GPIO_NUM_23
void app_main(void) {
    // Configure LED pin
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_reset_pin(BUTTON_GPIO);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(BUTTON_GPIO); // enable internal pull-up

    int last_button_state = 1;
    while (1) {
        //int button_state = gpio_get_level(BUTTON_GPIO); 
        int button_state = (GPIO.in >> BUTTON_GPIO) & 1; 
        if(button_state != last_button_state){
            vTaskDelay(50 / portTICK_PERIOD_MS);  // wait 50 ms
            //button_state = gpio_get_level(BUTTON_GPIO);
            button_state = (GPIO.in >> BUTTON_GPIO) & 1;
            if(button_state != last_button_state){
                if(button_state)
                    //gpio_set_level(LED_GPIO, 0); // LED off
                    GPIO.out_w1tc = (1 << LED_GPIO); 
                else
                    GPIO.out_w1ts = (1 << LED_GPIO); 
                last_button_state = button_state;
            }
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

