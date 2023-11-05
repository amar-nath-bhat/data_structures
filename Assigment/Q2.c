#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the stack
struct Stack {
    char data[100];  // Assuming a maximum tag length of 100 characters
    int top;
};

// Initialize an empty stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack *stack, char element) {
    stack->data[++stack->top] = element;
}

// Pop an element from the stack
char pop(struct Stack *stack) {
    return stack->data[stack->top--];
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to count missing or invalid tags
int countMissingInvalidTags(const char *input) {
    struct Stack stack;
    initStack(&stack);

    int count = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (input[i] == '<') {
            if (i + 1 < len && input[i + 1] == '/') {
                // Closing tag
                if (!isEmpty(&stack)) {
                    char openTag = pop(&stack);
                    while (i < len && input[i] != '>')
                        i++;
                    if (i == len || input[i] != '>')
                        count++;
                } else {
                    count++;
                }
            } else {
                // Opening tag
                int j = i + 1;
                while (j < len && input[j] != '>')
                    j++;
                if (j == len || input[j] != '>') {
                    count++;
                } else {
                    char tag[100];
                    strncpy(tag, input + i + 1, j - i - 1);
                    tag[j - i - 1] = '\0';
                    push(&stack, tag);
                }
                i = j;
            }
        }
    }

    // Count any remaining unclosed tags
    count += stack.top + 1;

    return count;
}

int main() {
    char exp[100];
    scanf("%s",exp);
    int count = countMissingInvalidTags(exp);
    printf("%d",count);
    return 0;
}
