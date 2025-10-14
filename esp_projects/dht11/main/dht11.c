#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"
#include "stdio.h"
#include "esp_timer.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "soc/gpio_struct.h"
#include "soc/gpio_reg.h"
#include "esp_sleep.h"

#define DHT_GPIO GPIO_NUM_23  //gpio for dht11 data read

//#define DELAY_TO_MS(ticks) 

void read_sensor(gpio_num_t pin, int* data){
    //1. Set GPIO to output
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
    //2. Drive low for 18 ms
    gpio_set_level(pin, 0);//set low
    const TickType_t low_timer = 30 / portTICK_PERIOD_MS; //make this a macro
    vTaskDelay(low_timer); //delay for 18ms

    //3. Drive high for 40 miscroseconds
    gpio_set_level(pin, 1);
    esp_rom_delay_us(400);

    //4. Read 40 bits
    //interrupt lock
    gpio_set_direction(pin, GPIO_MODE_INPUT);
    //TODO lock
    /*for(int i = 0; i < 40; i++){
        int tick_count=0;
        while(gpio_get_level(pin) == 0){ //busy waiting for high voltage
            //printf("LOW\n");
            //taskYIELD();
        }
        uint64_t start_time = esp_timer_get_time(); 
        while(gpio_get_level(pin) == 1){
            //printf("HIGH\n");
            //taskYIELD();
        }
        start_time = esp_timer_get_time() - start_time;
        if(start_time > 30) //assuming each tick is a miscrosecond?
            data[i] = 1;
        else
            data[i] = 0;
    }*/
    //TODO unlock
}
    
void app_main(void) {
    printf("Started DHT11 sensor reading\n");
    int data_bits[40];
     
    read_sensor(DHT_GPIO, data_bits);
    for (int i = 0; i < 40; i++) {
        read_sensor(DHT_GPIO, data_bits);
        //printf("%d", data_bits[i]);
    }
    printf("\n");
    //esp_deep_sleep(30 * 1000000 * 1000ULL);
    //taskYIELD();
}

