#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"

#include "freertos/task.h"
#include "driver/gpio.h"
#include "soc/gpio_struct.h"
#include "soc/gpio_reg.h"

#define DHT_GPIO GPIO_NUM_X  //gpio for dht11 data read

//#define DELAY_TO_MS(ticks) 

void read_sensor(auto pin, int* data){
    //1. Set GPIO to output
    pinMode(pin, OUTPUT)
    //2. Drive low for 18 ms
    gpio_set_level(pin, 0)//set low
    const TickType_t low_timer = 18 / portTICK_PERIOD_MS; //make this a macro
    vTaskDelay(low_timer); //delay for 18ms

    //3. Drive high for 40 miscroseconds
    gpio_set_level(pin, 1);
    vTaskDelay(1); //delay for 1 ms, this is the minimum

    //4. Read 40 bits
    //interrupt lock
    pinMode(pin, INPUT);//set to input
    for(int i = 0; i < 40; i++){
        int tick_count=0;
        while(gpio_get_level(pin) == 0); //busy waiting for high voltage
            
        while(gpio_get_level(pin))
            tick_count++;

        if(tick_count > 30) //assuming each tick is a miscrosecond?
            data[i] = 1;
        else
            data[i] = 0;
    }
    
void app_main(void) {
    int data_bits[40];

    read_sensor(DHT_GPIO, data);
    for (int i = 0; i < 40; i++) {
        printf("%d", data_bits[i]);
    }
    printf("\n");
}

