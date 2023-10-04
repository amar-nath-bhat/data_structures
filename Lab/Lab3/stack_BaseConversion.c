#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int a[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", item);
        return;
    }
    stack->top++;
    stack->a[stack->top] = item;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1;
    }
    int poppedItem = stack->a[stack->top];
    stack->top--;
    return poppedItem;
}

void display(struct Stack *stack, int n, int base) {
    int i;
    printf("Converted number: ");
    for (i = stack->top; i >= 0; i--) {
        if (stack->a[i] >= 10) {
            printf("%c", stack->a[i] + 'A' - 10);
        } else {
            printf("%d", stack->a[i]);
        }
    }
    printf(" in base %d\n", base);
}

int main() {
    int base;
    printf("Enter the base to which you want to convert: ");
    scanf("%d", &base);

    struct Stack stack;
    initialize(&stack);

    int a, n = 0;
    printf("Enter decimal number: ");
    scanf("%d", &a);

    while (a > 0) {
        push(&stack, a % base);
        a /= base;
        n++;
    }

    display(&stack, n, base);

    return 0;
}