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

void insertend(Node* head, int data){
    Node* newnode = create(data);
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void insertpos(Node* head, int pos, int data){
    if(head->next==NULL){
        Node* newnode = create(data);
        head->next = newnode;
        return;
    }

    Node* newnode = create(data);
    Node* temp=head;
    Node* temp1=temp->next;

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

void display(Node* head){
    if(head->next==NULL){
        printf("List Empty\n");
        return;
    }
    Node* curr=head->next;

    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }printf("\n");
}

Node* reverse(struct Node **head_ref)
{
    Node *temp = NULL;
    Node *current = (*head_ref);
    Node *last = create(-1);
    temp = current->prev;
    (*head_ref)=NULL;
    current->prev=current->next;
    current->next=NULL;
    current=current->prev;
    while (current !=  NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL )
    {
        last->next = temp->prev;
    }
    deleteend(last);
    return last;
}

Node* add_long(Node* list1, Node* list2){

    int carry=0, t=0;
    Node* sum = create(-1);
    Node* temp1 = list1->next;
    Node* temp2 = list2->next;

    while(temp1!=NULL && temp2!=NULL){
        t = (temp1->data + temp2->data + carry);
        insertend(sum, t%10);
        carry = t/10;
        temp1=temp1->next;
        temp2=temp2->next;
    }

    while(temp1!=NULL){
        t = temp1->data + carry;
        insertend(sum, t%10);
        carry = t/10;
        temp1=temp1->next;
    }

    while(temp2!=NULL){
        t = temp2->data + carry;
        insertend(sum, t%10);
        carry = t/10;
        temp2=temp2->next;
    }

    return sum;
}

int main() {
    Node* num1 = create(-1);
    Node* num2 = create(-1);
    Node* sum;
    int number1, number2;
    printf("Enter first number: ");
    scanf("%d",&number1);
    printf("Enter second number: ");
    scanf("%d",&number2);
    while(number1!=0){
        insertend(num1, number1%10);
        number1/=10;
    }
    while(number2!=0){
        insertend(num2, number2%10);
        number2/=10;
    }

    printf("Sum is: ");
    sum=add_long(num1, num2);
    display(reverse(&sum));

    return 0;
}
