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

Node* concat(Node* head1, Node* head2){
    Node* temp1=head1;
    Node* temp2=head2->next;

    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp2;
    temp2->prev=temp1;
    return head1;
}

void display(Node* head){
    if(head->next==NULL){
        printf("List Empty\n");
        return;
    }
    Node* curr=head->next;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

int main()
{
    Node *head1=create(-1), *head2=create(-1);
    int n1, n2, data;

    printf("Enter no of elements in List 1: ");
    scanf("%d",&n1);
    while(n1>0)
    {
        printf("Enter data to insert: ");
        scanf("%d",&data);
        insertend(head1, data);
        n1--;
    }

    printf("Enter no of elements in List 2: ");
    scanf("%d",&n2);
    while(n2>0)
    {
        printf("Enter data to insert: ");
        scanf("%d",&data);
        insertend(head2, data);
        n2--;
    }

    printf("List 1: ");
    display(head1);
    printf("\n");
    printf("List 2: ");
    display(head2);
    printf("\n");

    head1=concat(head1, head2);
    printf("Concated List: ");
    display(head1);

}