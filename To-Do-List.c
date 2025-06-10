#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_LENGTH 100

typedef struct {
    char description[MAX_LENGTH];
    int completed;
} Task;

Task toDoList[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter the task description: ");
    getchar(); // Clear input buffer
    fgets(toDoList[taskCount].description, MAX_LENGTH, stdin);
    toDoList[taskCount].description[strcspn(toDoList[taskCount].description, "\n")] = 0; // Remove newline
    toDoList[taskCount].completed = 0;
    taskCount++;
    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks in the list yet.\n");
        return;
    }
    printf("\nYour To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%s] %s\n", i + 1, toDoList[i].completed ? "Done" : "Pending", toDoList[i].description);
    }
}

void markDone() {
    int taskNum;
    printf("Enter the task number to mark as done: ");
    scanf("%d", &taskNum);

    if (taskNum < 1 || taskNum > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    toDoList[taskNum - 1].completed = 1;
    printf("Task marked as done!\n");
}

int main() {
    int choice;
    
    printf("****************************\n");
    printf("**   Welcome to To-Do List  **\n");
    printf("****************************\n");

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Done\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markDone(); break;
            case 4: printf("Exiting... Have a productive day!\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
