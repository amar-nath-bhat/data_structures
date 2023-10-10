#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* create(struct node* start)
{
    
    if(start==NULL)
    {
        int num, data, i;
        printf("Enter the no of nodes you want to create: ");
        scanf("%d",&num);
        if(num!=0)
        {
            struct node *temp; 
            struct node *newnode;
            newnode=malloc(sizeof(struct node*));
            printf("Enter the element to add: ");
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            start=newnode;
            temp=newnode;
            for(i=2;i<=num;i++)
            {
                newnode=malloc(sizeof(struct node*));
                printf("Enter the element to add: ");
                scanf("%d",&data);
                temp->next=newnode;
                newnode->data=data;
                newnode->next=NULL;
                temp=temp->next;
            } 
        }
    }
    return start;
}

void display(struct node* start)
{
    if(start==NULL)
        printf("No list created\n");
    else
    {
        struct node* temp;
        temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

struct node* insertLast(struct node* start)
{
    int data;
    struct node* newnode = malloc(sizeof(struct node*));
    if(start==NULL)
    {
        start=newnode;
        printf("Enter the element to add: ");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
    }
    else
    {
        struct node *temp;
        temp=start;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        printf("Enter the element to add: ");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
    }
    return start;
}

struct node* insertFirst(struct node* start)
{
    int data;
    struct node* newnode = malloc(sizeof(struct node*));
    printf("Enter the element to add: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=start;
    start=newnode;
    return start;
}

struct node* deleteLast(struct node* start)
{
    struct node* temp;
    temp=start;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return start;
}

struct node* deleteFirst(struct node* start)
{
    struct node* temp;
    temp=start;
    temp=temp->next;
    start=temp;
    return start;
}

struct node* insertPos(struct node* start, int pos)
{
    int data;
    struct node *temp, *newnode;
    temp=start;
    while(pos-1>1)
    {
        temp=temp->next;
        pos--;
    }
    newnode = malloc(sizeof(struct node*));
    printf("Enter the element to add: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
    return start;
}

struct node* deletePos(struct node* start, int pos)
{
    struct node *temp, *prev=NULL;
    temp=start;
    while(pos-1>0)
    {
        prev=temp;
        temp=temp->next;
        pos--;
    }
    prev->next=temp->next;
    free(temp);
    
    return start;
}

struct node* insertBefore(struct node* start, int ele)
{
    int data;
    struct node *temp, *newnode, *prev=NULL;
    temp=start;
    while(temp->data!=ele)
    {
        prev=temp;
        temp=temp->next;
    }
    newnode = malloc(sizeof(struct node*));
    printf("Enter the element to add: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=temp;
    prev->next=newnode;
    return start;
}

struct node* insertAfter(struct node* start, int ele)
{
    int data;
    struct node *temp, *newnode, *next=NULL;
    temp=start;
    while(temp->data!=ele)
    {
        temp=temp->next;
    }
    next=temp->next;
    newnode = malloc(sizeof(struct node*));
    printf("Enter the element to add: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=next;
    temp->next=newnode;
    return start;
}

struct node* reverse(struct node* start)
{
    struct node *temp, *prev=NULL, *next;
    temp=start;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next; 
    }
    start=prev;
    return start;
}


int main()
{
    struct node* start=NULL;
    start=create(start);
    printf("\n");
    //insertLast(start);
    //start=insertFirst(start);
    //start=deleteLast(start);
    //start=deleteFirst(start);
    //start=insertPos(start, 3);
    //start=deletePos(start,3);
    //start=insertBefore(start, 3);
    //start=insertAfter(start,3);
    start=reverse(start);
    display(start);
}
