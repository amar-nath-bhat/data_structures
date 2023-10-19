#include <stdio.h>
#include <stdlib.h>

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

struct node* concat(struct node* start1, struct node* start2)
{
    struct node* temp;
    temp=start1;
    if(start1==NULL)
        return start2;
    if(start2==NULL)
        return start1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=start2;
    return start1;
}

struct node* insert(struct node* start, int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    if(start==NULL)
    {
        start=newnode;
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
        newnode->data=data;
        newnode->next=NULL;
    }
    return start;
}

struct node* merge1(struct node* start1, struct node* start2)
{
    struct node* start=NULL;
    struct node *temp1, *temp2;
    temp1=start1;
    temp2=start2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            start=insert(start, temp1->data);
            temp1=temp1->next;
        }
        else if(temp1->data>temp2->data)
        {
            start=insert(start, temp2->data);
            temp2=temp2->next;
        }
        else
        {
            start=insert(start, temp1->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp2!=NULL)
    {
        start=insert(start, temp2->data);
        temp2=temp2->next;
    }
    while(temp1!=NULL)
    {
        start=insert(start, temp1->data);
        temp1=temp1->next;
    }
    return start;
}

struct node* merge2(struct node *firsta, struct node *firstb)
{
    struct node *curra = firsta;
    struct node *currb = firstb;
    struct node *preva=NULL, *prevb=NULL;
    struct node *res=NULL;

    int pa=0, pb=0;

    if(firsta->data<=firstb->data)
    {
        pa=1;
        res=firsta;
    }
    else
    {
        pb=1;
        res=firstb;
    }

    while(curra!=NULL && currb!=NULL)
    {
        if(curra->data<=currb->data)
        {
            if(pb==1)
            {
                prevb->next=curra;
                pa=1;
                pb=0;
            }
            preva=curra;
            curra=curra->next;
        }
        else
        {
            if(pa==1)
            {
                preva->next=currb;
                pa=0;
                pb=1;
            }
            prevb=currb;
            currb=currb->next;
        }
    }
    if(curra)
        prevb->next=curra;
    if(currb)
        preva->next=currb;
    // display(res);
    return(res);
}

int main()
{
    struct node *start1=NULL, *start2=NULL, *start3=NULL;
    start1= create(start1);
    start2= create(start2);

    while(1)
    {
        printf("\nOptions:\n");
        printf("1) Concat 2 lists\n");
        printf("2) Merge into new list\n");
        printf("3) Merge without new list\n");
        printf("4) Exit\n");

        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: display(concat(start1, start2));
                    break;
                    
            case 2: start3=merge1(start1, start2);
                    display(start3);
                    break;

            case 3: display(merge2(start1, start2));
                    break;
                   
            case 4: exit(0);
            
            default:printf("Invalid Choice: Try again!\n");
            
        }
    }
}