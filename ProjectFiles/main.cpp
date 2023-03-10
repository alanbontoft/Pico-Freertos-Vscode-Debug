#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

#include "MathClass.h"

MathClass *pMath;

void led_task(void*)
{   
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    TickType_t delay;
    bool fast = false;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    
    pMath = new MathClass(1);

    /*
    while (true)
    {
        gpio_put(LED_PIN, 1);
        vTaskDelay(10 * pMath->value());
        gpio_put(LED_PIN, 0);
        vTaskDelay(10 * pMath->value());

        pMath->inc();

        if (pMath->value() == 11) pMath->setValue(1);
    }
    */

    while (true)
    {
        delay = fast ? 10 : 50;
        for (int i=0; i < 10; i++)
        {
            gpio_put(LED_PIN, 1);
            vTaskDelay(delay);
            gpio_put(LED_PIN, 0);
            vTaskDelay(delay);
        }

        fast = !fast;
    }
}

int main()
{
    stdio_init_all();

    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}
