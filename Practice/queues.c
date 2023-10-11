#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the queue
struct Queue {
    int elements[MAX_SIZE];
    int front;
    int rear;
};

// Initialize an empty queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

// Enqueue an element at the rear of the queue
void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->elements[q->rear] = data;
}

// Dequeue and return the front element of the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int data = q->elements[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset the queue
    } else {
        q->front++;
    }
    return data;
}

// Function to reverse a queue using recursion
void reverse(struct Queue* q) {
    if (!isEmpty(q)) {
        int data = dequeue(q);
        reverse(q);
        enqueue(q, data);
    }
}

// Display the contents of the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->elements[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 70);
    enqueue(&queue, 60);

    printf("Original Queue:\n");
    displayQueue(&queue);

    reverse(&queue);

    printf("\nReversed Queue:\n");
    displayQueue(&queue);

    return 0;
}
