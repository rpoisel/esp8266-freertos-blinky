#include <stddef.h>
#include <stdint.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_common.h"
#include "uart.h"

#include "user_config.h"

void helloworld(void *pvParameters)
{
    const portTickType xDelay = 1000 / portTICK_RATE_MS;
    for(;;)
    {
        printf("Hello World!\n");
        vTaskDelay(xDelay);
    }
}

//Init function 
void ICACHE_FLASH_ATTR user_init(void)
{
    uart_div_modify(UART0, UART_CLK_FREQ / (BIT_RATE_9600));
    xTaskCreate(helloworld, "hw", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
}
