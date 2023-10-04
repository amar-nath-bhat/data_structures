#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
// Structure to represent the stack
struct Stack {
char items[MAX_SIZE];
int top;
};
// Function to initialize the stack
void initialize(struct Stack *stack) {
stack->top = -1;
}
// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
return stack->top == -1;
}
// Function to check if the stack is full
int isFull(struct Stack *stack) {
return stack->top == MAX_SIZE - 1;
}
// Function to push an item onto the stack
void push(struct Stack *stack, int item) {
if (isFull(stack)) {
printf("Stack overflow, cannot push %d\n", item);
return;
}
stack->top++;
stack->items[stack->top] = item;
}
// Function to pop an item from the stack
char pop(struct Stack *stack) {
if (isEmpty(stack)) {
printf("Stack underflow, cannot pop\n");
return -1; // Return an error value
}
char poppedItem = stack->items[stack->top];
stack->top--;
return poppedItem;
}


int pallindrome(char a[], char b[]){
int flag=0;
for(int i=0;a[i]!='\0';i++){
    if(a[i]!=b[i]){
        flag=0;
        break;
    }
    else
        flag=1;
}
return flag;
}

int main() {
char a[100], b[100];
struct Stack stack;
initialize(&stack);
printf("Enter the string:\n");
scanf("%s",a);
int l=strlen(a);
for(int i=0;i<l;i++){
    push(&stack, a[i]);
}
for(int i=0;i<l;i++){
    b[i]=pop(&stack);
}

    if(pallindrome(a, b))
        printf("Given string is a palindrome.\n");
    else
        printf("Given string is not a palindrome.\n");

}