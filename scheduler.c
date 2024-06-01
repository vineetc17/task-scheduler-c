#include <stdio.h>
#include <limits.h>
#include "task.h"

void printTaskExecution(int time, int task_id) {
    printf("Time %d: Executing Task %d\n", time, task_id);
}

void printTaskCompletion(int task_id) {
    printf("Task %d completed\n", task_id);
}

void priorityScheduler() {
    int time = 0;
    while (1) {
        int highestPriority = -1;
        int taskToExecute = -1;
        for (int i = 0; i < taskCount; i++) {
            if (taskList[i].remainingTime > 0 && taskList[i].priority > highestPriority) {
                highestPriority = taskList[i].priority;
                taskToExecute = i;
            }
        }
        if (taskToExecute != -1) {
            printTaskExecution(time, taskList[taskToExecute].taskId);
            taskList[taskToExecute].remainingTime--;
            if (taskList[taskToExecute].remainingTime == 0) {
                printTaskCompletion(taskList[taskToExecute].taskId);
            }
        } else {
            break; // No more tasks to execute
        }
        time++;
        if (time > 100) break; // Arbitrary time limit for simulation
    }
}

void edfScheduler() {
    int time = 0;
    while (1) {
        int taskToExecute = -1;
        int earliestDeadline = INT_MAX;
        for (int i = 0; i < taskCount; i++) {
            if (taskList[i].remainingTime > 0 && taskList[i].deadline < earliestDeadline && taskList[i].arrivalTime <= time) {
                earliestDeadline = taskList[i].deadline;
                taskToExecute = i;
            }
        }
        if (taskToExecute != -1) {
            printTaskExecution(time, taskList[taskToExecute].taskId);
            taskList[taskToExecute].remainingTime--;
            if (taskList[taskToExecute].remainingTime == 0) {
                printTaskCompletion(taskList[taskToExecute].taskId);
                taskList[taskToExecute].deadline = INT_MAX; // Task is completed
            }
        }
        time++;
        if (time > 100) break; // Arbitrary time limit for simulation
    }
}

void roundRobinScheduler() {
    int time = 0;
    while (taskCount>0) {
        for (int i = 0; i < taskCount; i++) {
            if (taskList[i].remainingTime > 0) {   //Checks for remaining execution time.
                printTaskExecution(time, taskList[i].taskId);  //Calls the function from scheduler.c
                taskList[i].remainingTime--; 
                time++;
                if (taskList[i].remainingTime == 0) {          //If zero, the task is complete
                    printTaskCompletion(taskList[i].taskId);
                    taskCount--;
                }
            }
        }
        if (time > 100) break; // Arbitrary time limit for simulation
    }
}

//This function ensures that each task is allocated 1 unit of time till the task is end. This is basic of Round robin.

