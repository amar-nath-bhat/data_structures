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
    newnode = malloc(sizeof(struct node));
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

struct node* deletealt(struct node* start) {
    struct node *temp, *prev;
    temp = start;
    prev = NULL;

    while (temp != NULL && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        free(temp); 
        temp = prev->next;
    }

    return start;
}

void swap(struct node* p1, struct node* p2){
    int temp;
    temp= p1->data;
    p1->data = p2->data;
    p2->data = temp; 
}

void sort(struct node* start){
    struct node *temp, *curr, *min;
    curr = start;

    while(curr->next){
        min = curr;
        temp = curr->next;

        while(temp){
            if(temp->data < min->data)
                min = temp;

            temp = temp->next;
        }
        swap(min, curr);
        curr = curr->next;
    }
    
}

void insertInOrder(struct node *start, int data) {
    struct node *temp = start, *prev = NULL;
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (start == NULL || (start)->data > data) {
        newnode->next = start;
        start = newnode;
        return;
    }

    while (temp != NULL && temp->data < data) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;
}


int main()
{
    int index, ele;
    struct node *start=NULL;
    start=create(start);

    while (1){
        printf("\nOptions:\n");
        printf("1) Insert Last\n");
        printf("2) Insert First\n");
        printf("3) Delete Last\n");
        printf("4) Delete First\n");
        printf("5) Insert at Position\n");
        printf("6) Delete at Position\n");
        printf("7) Insert before\n");
        printf("8) Insert after\n");
        printf("9) Traverse list\n");
        printf("10) Reverse List\n");
        printf("11) Delete Alternate Nodes\n");
        printf("12) Sort the list\n");
        printf("13) Insert in Order\n");
        printf("0) Exit.\n");
        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 1:     start=insertLast(start);
                        break;

            case 2:     start=insertFirst(start);
                        break;

            case 3:     start=deleteLast(start);
                        break;

            case 4:     start=deleteFirst(start);
                        break;

            case 5:     printf("Enter the position to insert: ");
                        scanf("%d",&index);
                        start=insertPos(start, index);
                        break;

            case 6:     printf("Enter the position to delete: ");
                        scanf("%d",&index);
                        start=deletePos(start, index);
                        break;

            case 7:     printf("Enter the element to insert before: ");
                        scanf("%d",&ele);
                        start=insertBefore(start, ele);
                        break;

            case 8:     printf("Enter the element to insert after: ");
                        scanf("%d",&ele);
                        start=insertAfter(start, ele); 
                        break;

            case 9:     display(start);
                        break;

            case 10:    start=reverse(start);
                        break;

            case 11:    start=deletealt(start);
                        break;

            case 12:    sort(start);
                        break;

            case 13:    printf("Enter an element to insert: ");
                        scanf("%d",&ele);
                        insertInOrder(start, ele);
                        break;

            case 0:    exit(0);

            default: printf("Invalid Choice, try again!\n");

        }
    }
    
    printf("\n");

}
