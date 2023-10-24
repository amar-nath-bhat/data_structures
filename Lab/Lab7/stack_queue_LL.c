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
            newnode=malloc(sizeof(struct node));
            printf("Enter the element to add: ");
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            start=newnode;
            temp=newnode;
            for(i=2;i<=num;i++)
            {
                newnode=malloc(sizeof(struct node));
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
    struct node* newnode = malloc(sizeof(struct node));
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
    struct node* newnode = malloc(sizeof(struct node));
    printf("Enter the element to add: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=start;
    start=newnode;
    return start;
}

struct node* deleteLast(struct node* start)
{
    if(start==NULL)
        return start;

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

int main()
{
    struct node* stack = NULL;
    struct node* queue = NULL;

    int choice, op;
    printf("Enter Stack/Queue (1/2): ");
    scanf("%d",&choice);

    if(choice ==  1){
        while(op<=3){
            printf("\nChoose your operation: 1)Push 2)Pop 3)Display: \n");
            scanf("%d",&op);
            switch(op){
                case 1:
                    stack=insertLast(stack);
                    break;
                case 2:
                    stack=deleteLast(stack);
                    break;
                case 3: 
                    display(stack);
                    break;
            }
        }
    }

    else if(choice == 2){
        while(op<=3){
            printf("\nChoose your operation: 1)Enqueue 2)Dequeue 3)Display:\n");
            scanf("%d",&op);
            switch(op){
                case 1:
                    queue=insertLast(queue);
                    break;
                case 2:
                    queue=deleteFirst(queue);
                    break;
                case 3: 
                    display(queue);
                    break;
            }
        }
    }
}