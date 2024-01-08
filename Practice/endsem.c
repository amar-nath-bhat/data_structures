#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int coeff, power;
    struct Node* next;
} Node;

Node* createNode(int coeff, int power) {
    Node* newNode = malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** start, Node* newNode) {
    if (*start == NULL) {
        *start = newNode;
        return;
    }
    Node* temp = *start;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void readList(Node** start, int n) {
    while (n > 0) {
        int coeff, power;
        printf("Enter Coefficient: ");
        scanf("%d", &coeff);
        printf("Enter Power:");
        scanf("%d", &power);
        Node* newNode = createNode(coeff, power);
        printf("%d %d", newNode->coeff, newNode->power);
        insertNode(start, newNode);
        n--;
    }
}

void display(Node* start) {
    Node* temp = start;
    while (temp) {
        if (temp->next) {
            printf("%dx%d + ", temp->coeff, temp->power);
        } else {
            printf("%dx%d\n", temp->coeff, temp->power);
        }
        temp = temp->next;
    }
}

int main() {
    Node* start = NULL;
    Node* newNode = createNode(3, 4);
    insertNode(&start, newNode);
    readList(&start, 2);
    display(start);

    return 0;
}
