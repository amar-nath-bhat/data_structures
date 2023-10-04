#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

int push(char item) {
    if (isFull()) {
        printf("Stack is Full\n");
        return -1;
    } else {
        top++;
        stack[top] = item;
    }
    return 0;
}

char pop() {
    if (isEmpty()) {
        printf("Stack empty\n");
        return '\0';
    } else {
        char popped = stack[top];
        top--;
        return popped;
    }
}

int main() {
    char exp[MAX];
    printf("Enter the expression: \n");
    gets(exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmpty()) {
                printf("Parentheses do not match!\n");
                exit(0);
            } else {
                char val = pop();

                if ((exp[i] == ')' && val != '(') || (exp[i] == ']' && val != '[') || (exp[i] == '}' && val != '{')) {
                    printf("Parentheses do not match!\n");
                    exit(0);
                }
            }
        }
    }
    if (!isEmpty()) {
        printf("Parentheses do not match!\n");
    } else {
        printf("Parentheses are properly balanced.\n");
    }

    return 0;
}