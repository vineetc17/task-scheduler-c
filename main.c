#include <stdio.h>
#include "task.h"

void roundRobinScheduler();
void priorityScheduler();
void edfScheduler();

int main(){
    int numTasks, id, priority, executionTime, deadline, arrivalTime;
    int schedulerChoice;

    printf("Please enter the number of tasks: ");
    scanf("%d", &numTasks);

    for(int i=0; i<numTasks; i++){
        printf("Enter details for task %d: \n", i+1);

        printf("ID: ");
        scanf("%d", &id);

        printf("Priority: ");
        scanf("%d", &priority);

        printf("Execution Time: ");
        scanf("%d", &executionTime);

        printf("Deadline: ");
        scanf("%d", &deadline);

        printf("Arrival Time: ");
        scanf("%d", &arrivalTime);

        add_task(id, priority, executionTime, deadline, arrivalTime);
    }

    printf("Choose a scheduler to run:\n");
    printf("1. Round Robin\n");
    printf("2. Priority\n");
    printf("3. Earliest Deadline First\n");
    printf("4. Exit\n");
    scanf("%d", &schedulerChoice);

    switch (schedulerChoice) {
        case 1:
            roundRobinScheduler();
            break;
        case 2:
            priorityScheduler();
            break;
        case 3:
            edfScheduler();
            break;
        case 4:
            printf("Exiting..");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    return 0;
}