#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* create(int data){
    Node* newnode = malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void insertend(Node* head, int data){
    Node* newnode = create(data);
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void insertpos(Node* head, int pos){
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    Node* newnode = create(data);
    Node* temp=head;
    Node* temp1;

    while(pos>0){
        temp=temp->next;
        temp1=temp->next;
        pos--;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=temp1;
    temp1->prev=newnode;
}

void deleteend(Node* head){
    Node* temp=head;
    Node* temp1;
    while(temp->next!=NULL){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    temp=NULL;
}

void deletepos(Node* head, int pos){
    Node* temp=head;
    Node* temp1;
    Node* temp2;

    while(pos>0){
        temp2=temp;
        temp=temp->next;
        temp1=temp->next;
        pos--;
    }
    temp1->prev=temp->prev;
    temp2->next=temp->next;
    temp->next=NULL;
    temp->prev=NULL;
}

void insertafter(Node* head, int data1){
    int data2;
    printf("Enter target data: ");
    scanf("%d", &data2);
    Node* newnode = create(data1);
    Node* temp=head;
    Node* temp1=temp->next;

    while(temp->data!=data2){
        temp=temp->next;
        temp1=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=temp1;
}

void insertbefore(Node* head, int data1){
    int data2;
    printf("Enter target data: ");
    scanf("%d", &data2);
    Node* newnode = create(data1);
    Node* temp=head;
    Node* temp1=temp->next;

    while(temp->next->data!=data2){
        temp=temp->next;
        temp1=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=temp1;
    temp1->prev=newnode;
}

void display(Node* head){
    if(head->next==NULL){
        printf("List Empty\n");
        return;
    }
    Node* curr=head->next;
    printf("List: ");
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}


Node* reverse(Node* head) {
    Node *prev1, *curr;
    prev1=curr=NULL;
    while(head){
        prev1 = curr;
        curr =head;
        head = head->next;
        curr->next = prev1;
        if(prev1)
            prev1->prev = curr;
    }
    head = prev1;
    return head;
}



int main() {
    Node* head = create(-1);
    int choice;
    int data, pos;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at the rear end\n");
        printf("2. Delete from the rear end\n");
        printf("3. Insert at a given position\n");
        printf("4. Delete from a given position\n");
        printf("5. Insert after an element\n");
        printf("6. Insert before an element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the rear end: ");
                scanf("%d", &data);
                insertend(head, data);
                break;

            case 2:
                deleteend(head);
                break;
            
            case 3:
                printf("Enter position to insert at: ");
                scanf("%d",&pos);
                insertpos(head, pos);
                break;

            case 4:
                printf("Enter position to delete at: ");
                scanf("%d",&pos);
                deletepos(head, pos);
                break;

            case 5:
                printf("Enter element to insert: ");
                scanf("%d",&data);
                insertafter(head, data);
                break;

            case 6:
                printf("Enter element to insert: ");
                scanf("%d",&data);
                insertbefore(head, data);
                break;

            case 7:
                printf("List: ");
                display(head);
                break;

            case 8:
                reverse(head);
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

