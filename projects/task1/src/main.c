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
TASK(task1, TASK_STACK_512) {
  LOG_DEBUG("Task1 \n");

  int counter1 = 0;
  counter1++;
  LOG_DEBUG("counter1: %d\n Delay for 1sec \n", counter2);
  prv_delay(1000);
  LOG_DEBUG("End of delay and function \n");
}
TASK(task2, TASK_STACK_512) {
  LOG_DEBUG("Task2 \n");

  int counter2 = 0;
  counter2++;
  LOG_DEBUG("counter2: %d\n Delay for 1sec \n", counter2);
  prv_delay(1000);
  LOG_DEBUG("End of delay and function \n");
}

int main(void) {
    log_init();
    tasks_init();
    tasks_init_task(task1, TASK_PRIORITY(1), NULL);
    tasks_init_task(task2, TASK_PRIORITY(2), NULL);

    LOG_DEBUG("Program start...\n");
    tasks_start();
    return 0;
}
