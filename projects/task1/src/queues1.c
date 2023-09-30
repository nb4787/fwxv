#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "tasks.h"
#include "queues.h"
#include "status.h"
#include "delay.h"

#include "log.h"
#include "misc.h"


#define ITEM_SZ 6
#define QUEUE_LEN 5
#define BUF_SIZE (QUEUE_LEN * ITEM_SZ)

static const char s_list[QUEUE_LEN][ITEM_SZ] = {
	"Item1",
	"Item2",
	"Item3",
	"Item4",
	"Item5"
};

// Task static entities
static uint8_t s_queue1_buf[BUF_SIZE];
static Queue s_queue1 = {
  .num_items = QUEUE_LEN,
  .item_size = ITEM_SZ,
  .storage_buf = BUF_SIZE,
};


TASK(task1, TASK_STACK_512) {
  LOG_DEBUG("Task 1 initialized!\n");
  StatusCode ret;
  int i = 0;
  char* item = s_list[i];

  while (true) {
    queue_send(&s_queue1,item, 0);
    delay_ms(100);
    i++;
  }
}

TASK(task2, TASK_STACK_512) {
  LOG_DEBUG("Task 2 initialized!\n");
  const char outstr[ITEM_SZ];
  char* receive;
  StatusCode ret;
  while (true) {
    queue_receive(&s_queue1,receive,0);
    delay_ms(500);
    LOG_DEBUG("Received: %u\n", receive);
  }
}

int main(void) {
  log_init();
  // Initialize queues here
  queue_init(&s_queue1);
  tasks_init_task(task1, TASK_PRIORITY(2), NULL);
  tasks_init_task(task2, TASK_PRIORITY(2), NULL);

  LOG_DEBUG("Program start...\n");
  tasks_start();

  return 0;
}