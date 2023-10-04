#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push(int item, int stackNumber) {
    if (stackNumber == 1) {
        if (top1 == MAX - 1) {
            printf("Stack 1 is full.\n");
        } else {
            stack[++top1] = item;
        }
    } else if (stackNumber == 2) {
        if (top2 == 0) {
            printf("Stack 2 is full.\n");
        } else {
            stack[--top2] = item;
        }
    } else {
        printf("Invalid stack number.\n");
    }
}

int pop(int stackNumber) {
    int item = -1;
    if (stackNumber == 1) {
        if (top1 == -1) {
            printf("Stack 1 is empty.\n");
        } else {
            item = stack[top1--];
        }
    } else if (stackNumber == 2) {
        if (top2 == MAX) {
            printf("Stack 2 is empty.\n");
        } else {
            item = stack[top2++];
        }
    } else {
        printf("Invalid stack number.\n");
    }
    return item;
}

void display(int stackNumber) {
    if (stackNumber == 1) {
        if (top1 == -1) {
            printf("Stack 1 is empty.\n");
        } else {
            printf("Stack 1: ");
            for (int i = 0; i <= top1; i++) {
                printf("%d ", stack[i]);
            }
            printf("\n");
        }
    } else if (stackNumber == 2) {
        if (top2 == MAX) {
            printf("Stack 2 is empty.\n");
        } else {
            printf("Stack 2: ");
            for (int i = MAX - 1; i >= top2; i--) {
                printf("%d ", stack[i]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid stack number.\n");
    }
}

int main() {
    int choice, stackNumber, item;

    while (1) {
        printf("Select your desired operation:\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Display\n");
        printf("4) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item, stackNumber);
                break;
            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                item = pop(stackNumber);
                if (item != -1) {
                    printf("Popped element: %d\n", item);
                }
                break;
            case 3:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                display(stackNumber);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}