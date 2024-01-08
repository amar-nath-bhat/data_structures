#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next, *prev;
}Node;

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->next =newNode->prev = newNode;
    return newNode;
}

void insertEnd(Node* start, int data){
    if(start==NULL){
        Node* newNode = createNode(data);
        start=newNode;
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = start->next;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->prev =temp;
    newNode->next =start;
    start->prev=newNode;
}

// void delete(Node* start, int key){
//     if(start==NULL)
//         return;
//     Node* temp = start, *prev;
//     while(temp->data!=key){
//         prev=temp;
//         temp=temp->next;
//     }
    
//     prev->next=temp->next;
//     temp->next->prev=prev;
// }

void delete(struct Node** start, int key)
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

void display(Node* start){
    Node* temp = start;
    do{
        printf("%d\t", temp->data);
        temp=temp->next;
    }while(temp!=start);
}


int main(){
    Node* start = createNode(1);
    insertEnd(start, 2);
    insertEnd(start, 3);
    insertEnd(start, 4);
    insertEnd(start, 5);
    insertEnd(start, 6);
    insertEnd(start, 7);
    delete(&start, 1);
    // printf("%d", start->data);
    display(start);

}