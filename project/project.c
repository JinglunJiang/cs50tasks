#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

struct Task
{
    char description[MAX_LENGTH];
    int completed;
};

struct Task taskList[MAX_TASKS];
int numTasks = 0;

void addTask(const char* description)
{
    if (numTasks >= MAX_TASKS)
    {
        printf("Cannot add more tasks. Task list is full.\n");
        return;
    }

    struct Task newTask;
    strcpy(newTask.description, description);
    newTask.completed = 0;

    taskList[numTasks++] = newTask;

    printf("Task added: %s\n", description);
}

void completeTask(int taskIndex)
{
    if (taskIndex < 0 || taskIndex >= numTasks)
    {
        printf("Invalid task index.\n");
        return;
    }

    if (taskList[taskIndex].completed)
    {
        printf("Task is already completed.\n");
        return;
    }

    taskList[taskIndex].completed = 1;

    printf("Task completed: %s\n", taskList[taskIndex].description);
}

void listTasks()
{
    if (numTasks == 0)
    {
        printf("No tasks to display.\n");
        return;
    }

    printf("Tasks:\n");

    for (int i = 0; i < numTasks; i++)
    {
        const char* status = taskList[i].completed ? "[X]" : "[ ]";
        printf("%d. %s %s\n", i + 1, status, taskList[i].description);
    }
}

int main()
{
    char command[MAX_LENGTH];

    while (1)
    {
        printf("\nPlease enter a command (add, complete, list, or exit): ");
        fgets(command, MAX_LENGTH, stdin);

        if (strcmp(command, "exit\n") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else if (strcmp(command, "add\n") == 0)
        {
            char description[MAX_LENGTH];
            printf("Enter the task description: ");
            fgets(description, MAX_LENGTH, stdin);
            addTask(description);
        }
        else if (strcmp(command, "complete\n") == 0)
        {
            int taskIndex;
            printf("Enter the task index: ");
            scanf("%d", &taskIndex);
            getchar();  // Clear the newline character from the buffer
            completeTask(taskIndex - 1);
        }
        else if (strcmp(command, "list\n") == 0)
        {
            listTasks();
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
