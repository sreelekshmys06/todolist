#include <stdio.h>
#include <string.h>

#define MAX_TASKS 50
#define TASK_LENGTH 100

int main() {
    char tasks[MAX_TASKS][TASK_LENGTH];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\n--- TO-DO LIST APPLICATION ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline

        if (choice == 1) {
            if (taskCount >= MAX_TASKS) {
                printf("Task list is full!\n");
            } else {
                printf("Enter task: ");
                fgets(tasks[taskCount], TASK_LENGTH, stdin);
                tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0';
                taskCount++;
                printf("Task added successfully!\n");
            }
        }
        else if (choice == 2) {
            if (taskCount == 0) {
                printf("No tasks added yet.\n");
            } else {
                printf("\nYour Tasks:\n");
                for (int i = 0; i < taskCount; i++) {
                    printf("%d. %s\n", i + 1, tasks[i]);
                }
            }
        }
        else if (choice == 3) {
            printf("Exiting application. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
