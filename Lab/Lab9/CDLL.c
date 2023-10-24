/*Write a menu driven program to:
ii) Insert an element into a doubly linked circular list
iii) Delete an element from a doubly linked circular list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertEnd(struct Node** start, int value)
{
    if (*start == NULL)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    // If list is not empty

    /* Find last node */
    struct Node *last = (*start)->prev;

    // Create Node dynamically
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;

    // Start is going to be next of new_node
    new_node->next = *start;

    // Make new node previous of start
    (*start)->prev = new_node;

    // Make last previous of new node
    new_node->prev = last;

    // Make new node next of old last
    last->next = new_node;
}

void deleteNode(struct Node** start, int key)
{
    if (*start == NULL)
        return;
    struct Node *curr = *start, *prev_1 = NULL;
    while (curr->data != key) {
        if (curr->next == *start) {
            printf("\nList doesn't have node with value = %d", key);
            return;
        }

        prev_1 = curr;
        curr = curr->next;
    }
    if (curr->next == *start && prev_1 == NULL) {
        (*start) = NULL;
        free(curr);
        return;
    }
    if (curr == *start) {
        prev_1 = (*start)->prev;
        *start = (*start)->next;


        prev_1->next = *start;
        (*start)->prev = prev_1;
        free(curr);
    }
    else if (curr->next == *start) {

        prev_1->next = *start;
        (*start)->prev = prev_1;
        free(curr);
    }
    else {
        struct Node* temp = curr->next;
        prev_1->next = temp;
        temp->prev = prev_1;
        free(curr);
    }
}

void display(struct Node* start)
{
    struct Node *temp = start;

    printf("Traversal in forward direction \n");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

    printf("\nTraversal in reverse direction \n");
    struct Node *last = start->prev;
    temp = last;
    while (temp->prev != last)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main(){
    struct Node* start=NULL;
    for(int i=0;i<10;i++)
        insertEnd(&start,i);
    deleteNode(&start,5);
    display(start);
}