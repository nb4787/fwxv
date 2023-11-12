#include "tasks.h"

#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "delay.h"
#include "gpio.h"
#include "log.h"
#include "misc.h"

// Non blocking delay. Simply consumes cpu cycles until a given time has passed
static void prv_delay(const TickType_t delay_ms) {
  TickType_t curr_tick = xTaskGetTickCount();
  while (xTaskGetTickCount() - curr_tick < pdMS_TO_TICKS(delay_ms)) {
  }
}

TASK(task1, TASK_STACK_512) {
  TickType_t curr_tick = xTaskGetTickCount();
  int counter1 = 0;
  while (counter1 < 10) {  //&& (xTaskGetTickCount() - curr_tick > 1)) {
    LOG_DEBUG("\ntask1");
    LOG_DEBUG("%i\n", counter1);
    prv_delay(1);
    ++counter1;
  }
}

TASK(task2, TASK_STACK_512) {
  TickType_t curr_tick = xTaskGetTickCount();
  int counter2 = 0;
  while (counter2 < 10) {  //&& (xTaskGetTickCount() - curr_tick > 1)) {
    LOG_DEBUG("\ntask2");
    LOG_DEBUG("%i\n", counter2);
    prv_delay(1);
    ++counter2;
  }
}

TASK(GPIO_LED, TASK_STACK_512) {
  TickType_t curr_tick = xTaskGetTickCount();
  GpioAddress led1 = {
    .port = GPIO_PORT_B,
    .pin = 5,
  };
  GpioAddress led2 = {
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

  const GpioAddress *addr_led1 = &led1;
  const GpioAddress *addr_led2 = &led2;
  const GpioAddress *addr_led3 = &led3;
  const GpioAddress *addr_led4 = &led4;

  const GpioMode pin_mode_led1 = GPIO_OUTPUT_PUSH_PULL;
  const GpioMode pin_mode_led2 = GPIO_OUTPUT_PUSH_PULL;
  const GpioMode pin_mode_led3 = GPIO_OUTPUT_PUSH_PULL;
  const GpioMode pin_mode_led4 = GPIO_OUTPUT_PUSH_PULL;

  GpioState state_led1 = GPIO_STATE_HIGH;
  GpioState state_led2 = GPIO_STATE_HIGH;
  GpioState state_led3 = GPIO_STATE_HIGH;
  GpioState state_led4 = GPIO_STATE_HIGH;

  gpio_init_pin(addr_led1, pin_mode_led1, state_led1);
  gpio_init_pin(addr_led2, pin_mode_led2, state_led2);
  gpio_init_pin(addr_led3, pin_mode_led3, state_led3);
  gpio_init_pin(addr_led4, pin_mode_led4, state_led4);

  while (true) {
    gpio_toggle_state(addr_led1);
    prv_delay(1);
    gpio_toggle_state(addr_led2);
    prv_delay(1);
    gpio_toggle_state(addr_led3);
    prv_delay(1);
    gpio_toggle_state(addr_led4);
    prv_delay(1);
  }
}

int main(void) {
  gpio_init();
  log_init();
  tasks_init();
  // Create tasks here
  tasks_init_task(GPIO_LED, TASK_PRIORITY(1), NULL);

  LOG_DEBUG("Program start...\n");
  // Start the scheduler
  tasks_start();
  exit(0);
  return 0;
}
