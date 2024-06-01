#ifndef TASK_H
#define TASK_H

#define MAX_TASKS 10   

typedef struct {
    int taskId;
    int priority;
    int executionTime;
    int deadline;
    int remainingTime;
    int arrivalTime;
} Task;

extern Task taskList[MAX_TASKS];
extern int taskCount;

void add_task(int id, int priority, int exec_time, int deadline, int arrival_time);

#endif // TASK_H
