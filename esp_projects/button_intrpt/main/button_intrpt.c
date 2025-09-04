#include "soc/gpio_struct.h"
#include "soc/gpio_reg.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_timer.h"
// Macros for LED control
#define LED_GPIO GPIO_NUM_2  // onboard LED on most ESP32 dev boards
#define BUTTON_GPIO GPIO_NUM_23
#define LED_ON()   (GPIO.out_w1ts = (1 << LED_GPIO))
#define LED_OFF()  (GPIO.out_w1tc = (1 << LED_GPIO))
#define LED_TOGGLE() GPIO.out ^= (1 << LED_GPIO); // flip LED state
// Macro for button read
#define BUTTON_READ() ((GPIO.in >> BUTTON_GPIO) & 0x1)

static void IRAM_ATTR button_isr(void* arg) {
    static int64_t last_time = 0;
    int64_t now = esp_timer_get_time(); // current time in microseconds
    if (now - last_time > 50000) {      // 50 ms debounce
        int state = (GPIO.in >> BUTTON_GPIO) & 1;
        if(state == 0) { // pin is low, button pressed
            LED_TOGGLE();
        }
        last_time = now;
    }
}
void app_main(void) {
    // Configure LED pin
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_pullup_en(BUTTON_GPIO); 
    gpio_set_intr_type(BUTTON_GPIO, GPIO_INTR_NEGEDGE);  // falling edge
    gpio_install_isr_service(0);
    gpio_isr_handler_add(BUTTON_GPIO, button_isr, NULL);

    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    //what needs to go here?
    while(1){
        vTaskDelay(portMAX_DELAY);
    }

}

