#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "tasks.h"

#include "gpio.h"
#include "log.h"
#include "misc.h"
#include "delay.h"

// Non blocking delay. Simply consumes cpu cycles until a given time has passed

static void prv_delay(const TickType_t delay_ms) {
  TickType_t curr_tick = xTaskGetTickCount();
  while(xTaskGetTickCount() - curr_tick < pdMS_TO_TICKS(delay_ms))
  {}
}

GpioAddress led1 = {
  .port = GPIO_PORT_B,
  .pin = 5,
};GpioAddress led2 = {
  .port = GPIO_PORT_B,
  .pin = 4,
};
GpioAddress led3 = {
  .port = GPIO_PORT_B,
  .pin = 3,
};
GpioAddress led4 = {
  .port = GPIO_PORT_A,
  .pin = 15,
};


TASK(task1, TASK_STACK_512) {
  int counter1 = 0;
  while (true) {
   gpio_toggle_state(&led1);
   prv_delay(1000);
   gpio_toggle_state(&led2);
   prv_delay(1000);
   gpio_toggle_state(&led3);
   prv_delay(1000);
   gpio_toggle_state(&led4);
   prv_delay(1000);
  }
}


int main(void) {
    log_init();
    tasks_init();
    gpio_init();
    gpio_init_pin(&led1, GPIO_OUTPUT_PUSH_PULL, GPIO_STATE_HIGH);
    gpio_init_pin(&led2, GPIO_OUTPUT_PUSH_PULL, GPIO_STATE_HIGH);
    gpio_init_pin(&led3, GPIO_OUTPUT_PUSH_PULL, GPIO_STATE_HIGH);
    gpio_init_pin(&led4, GPIO_OUTPUT_PUSH_PULL, GPIO_STATE_HIGH);
    // Create tasks here
   tasks_init_task(task1, TASK_PRIORITY(2), NULL);
    LOG_DEBUG("Program start...\n");
    // Start the scheduler
   tasks_start();
    return 0;
}