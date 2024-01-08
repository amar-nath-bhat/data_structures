#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* createList(int n){
    struct Node* start;
    if(n>0){
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        struct Node* newNode, *temp;
        newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        start = newNode;
        temp = start;
        while(n>1){
            printf("Enter data: ");
            scanf("%d",&data);
            newNode = malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = NULL;
            temp->next = newNode;
            temp=temp->next;
            n--;
        }
    }
    return start;
}

struct Node* insertEnd(struct Node* start){
    struct Node* temp = start;
    if(start==NULL)
        return NULL;

    while(temp->next){
        temp=temp->next;
    }
    struct Node* newNode = malloc(sizeof(struct Node));
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    newNode->data=data;
    newNode->next=NULL;
    temp->next = newNode;
    return start;
}

struct Node* insertFirst(struct Node* start, int data){
    if(start==NULL){
        struct Node* newNode = malloc(sizeof(struct Node*));
        newNode->data = data;
        newNode->next=NULL;
        start = newNode;
        return start;
    }
    else{
        struct Node* temp = start;
        struct Node* newNode = malloc(sizeof(struct Node*));
        newNode->data = data;
        newNode->next=temp;
        return newNode;
    }
}

struct Node* delete(struct Node* start, int data){
    if(start->data==data){
        start=start->next;
        return start;
    }

    struct Node* temp = start;
    while(temp->next->data!=data){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return start;
}

void display(struct Node* start){
    struct Node* temp =start;
    if(start==NULL){
        printf("List EMPTY!!!");
        return;
    }
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct Node* reverse(struct Node* start){
    struct Node *next, *temp, *prev=NULL;
    temp=start;
    while(temp){
        next=temp->next;
        temp->next = prev;
        prev=temp;
        temp=next;
    }
    start = prev;
    return start;
}


int main(){
    struct Node* start =  createList(5);
    // start=insertEnd(start);
    // start=insertFirst(start, 7);
    // display(start);
    start = reverse(start);
    display(start);
}