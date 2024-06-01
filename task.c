#include "task.h"

Task taskList[MAX_TASKS];
taskCount = 0;

void add_task(int id, int priority, int exec_time, int deadline, int arrival_time) {
    if (taskCount < MAX_TASKS) {
        taskList[taskCount].taskId = id;
        taskList[taskCount].priority = priority;
        taskList[taskCount].executionTime = exec_time;
        taskList[taskCount].deadline = deadline;
        taskList[taskCount].remainingTime = exec_time;
        taskList[taskCount].arrivalTime = arrival_time;
        taskCount++;
    }
}
