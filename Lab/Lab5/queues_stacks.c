#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int stack1[MAX];
int stack2[MAX];
int top1 = -1;
int top2 = -1;

int isEmpty() {
    return (top1 == -1 && top2 == -1);
}

int isFull() {
    return (top1 == MAX - 1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else {
        stack1[++top1] = item;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else if (top2 == -1) {
        // Transfer elements from stack1 to stack2 for dequeue
        while (top1 >= 0) {
            stack2[++top2] = stack1[top1--];
        }
    }
    int item = stack2[top2--];
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= top2; i++) {
        printf("%d ", stack2[i]);
    }
    for (int i = top1; i >= 0; i--) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);

    dequeue();
    dequeue();

    display();

    return 0;
}