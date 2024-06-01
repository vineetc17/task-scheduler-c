# Implementation of Task Scheduling Algorithms in C

This project implements a task scheduler simulation in C, demonstrating three different scheduling algorithms: Round Robin, Priority Scheduling, and Earliest Deadline First (EDF) Scheduling.

## Project Structure

The project consists of the following files:

- `main.c`: The main entry point of the program. It handles user input and invokes the selected scheduler.
- `task.c`: Contains functions to manage tasks, including adding tasks to the task list.
- `task.h`: Header file defining the Task structure and declaring functions and variables related to task management.
- `scheduler.c`: Implements the three scheduling algorithms and utility functions to simulate task execution and completion.

## Files Description

### main.c

This file contains the main function, which:
1. Prompts the user to enter the number of tasks and their details.
2. Adds each task to the task list.
3. Prompts the user to choose a scheduling algorithm to run.
4. Executes the chosen scheduling algorithm.

### task.c

This file contains:
- An array to store tasks (`taskList`) and a counter (`taskCount`) to keep track of the number of tasks.
- The `add_task` function to add tasks to the task list.

### task.h

This file defines the `Task` structure and declares:
- The maximum number of tasks (`MAX_TASKS`).
- The `taskList` array and `taskCount` variable.
- The `add_task` function.

### scheduler.c

This file contains the implementation of the three scheduling algorithms:
- `priorityScheduler`: Executes tasks based on their priority.
- `edfScheduler`: Executes tasks based on their earliest deadline.
- `roundRobinScheduler`: Executes tasks in a round-robin manner, giving each task an equal share of CPU time.

Additionally, it includes helper functions:
- `printTaskExecution`: Prints a message when a task is executed.
- `printTaskCompletion`: Prints a message when a task is completed.

## How to Compile and Run

1. Compile the project using a C compiler:
   ```sh
   gcc main.c task.c scheduler.c -o scheduler
2. Run the project:
   ```sh
   ./scheduler
   
## Example
Prompts:
```plaintext
Please enter the number of tasks: 2

Enter details for task 1:
ID: 1
Priority: 5
Execution Time: 3
Deadline: 10
Arrival Time: 0

Enter details for task 2:
ID: 2
Priority: 3
Execution Time: 2
Deadline: 5
Arrival Time: 1

Choose a scheduler to run:
1. Round Robin
2. Priority
3. Earliest Deadline First
4. Exit
2
```
Output:
```
Time 0: Executing Task 1
Time 1: Executing Task 1
Time 2: Executing Task 1
Task 1 completed
Time 3: Executing Task 2
Time 4: Executing Task 2
Task 2 completed
```
