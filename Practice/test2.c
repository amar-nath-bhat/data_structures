#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *last=NULL;

void createlist()
{
    if(last==NULL)
    {
        int n,data;
        struct node *lk=(struct node*)malloc(sizeof(struct node));
        printf("Enter number of nodes: ");
        scanf("%d",&n);
        printf("Enter element to be inserted: ");
        scanf("%d",&data);
        lk->data=data;
        lk->next=lk;
        lk->prev=lk;
        last=lk;
        for(int i=2;i<=n;i++)
        {
            lk=malloc(sizeof(struct node));
            printf("Enter element to be inserted: ");
            scanf("%d",&data);
            lk->data=data;
            lk->prev=last;
            lk->next=last->next;
            last=lk;
        }
        printf("\nList has been created\n");
    }
    else
        printf("\nList has already been created\n");
}

void printlist()
{
    if(last==NULL)
        printf("\nList is empty\n");
    else
    {
        struct node *p;
        p=last;
        printf("List is: [ ");
        while(p->next!=last)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("]\n");
    }
}

void insertele(int data,int pos)
{
    struct node *lk=(struct node*)malloc(sizeof(struct node));
    struct node *p=last->next;
    lk->data=data;
    for(int i=1;i<pos;i++)
    {
        p=p->next;
    }
    p->prev->next=lk;
    lk->prev=p->prev;
    lk->next=p;
    p->prev=lk;
}

void delele(int pos)
{
    struct node *p=last->next;
    for(int i=1;i<pos;i++)
    {
        p=p->next;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
}

int main()
{
    int choice,data,pos;
    printf("\nEnter 1 to create a linked list\n");
    printf("Enter 2 to display linked list\n");
    printf("Enter 3 to insert an element in the list\n");
    printf("Enter 4 to delete an element in the list\n");
    printf("Enter 5 to exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            createlist();
            break;
        case 2:
            printlist();
            break;
        case 3:
            printf("Enter element to be inserted: ");
            scanf("%d",&data);
            printf("Enter position of insertion: ");
            scanf("%d",&pos);
            insertele(data,pos);
            break;
        case 4:
            printf("Enter position of deletion: ");
            scanf("%d",&pos);
            delele(pos);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice, enter a valid option\n");
        }
    }
}











