#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char name[100];
    struct Node * next;
}Node;

Node * head = NULL;
Node * curr = NULL;

void insert(void)
{
    Node * temp = (Node *) malloc(sizeof(Node));
    printf("Enter your name: ");
    scanf("%s", temp -> name);

    temp -> next = head;
    curr -> next = temp;
    curr = temp;
}

void delete(void)
{
    char a[100];
    printf("Enter name through which booking made: ");
    scanf("%s", a);
    Node * temp = NULL, * prev = head;

    for(temp = head -> next; temp != head; prev = temp, temp = temp -> next)
    {
        if(strcmp(a, temp -> name) == 0)
        {
            prev -> next = temp -> next;
            free(temp);
            break;
        }
    }
}

void disp(void)
{
    Node * temp = head -> next;
    if(temp == head)
    {
        printf("Queue is empty\n");
    }

    else
    {
        printf("Queue: ");
        while(temp != head)
        {
            printf("%s\t", temp -> name);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void pos(void)
{
    Node * temp = head -> next;
    char a[100];
    printf("Enter name: ");
    scanf("%s", a);
    int flag = 0, count = 0;

    while(temp != head)
    {
        count++;
        if(strcmp(temp -> name, a) == 0)
        {
            flag = 1;
            break;
        }
        temp = temp -> next;
    }

    if(flag == 1)
    {
        printf("Your queue position is : %d\n", count);
    }

    else
    {
        printf("Name not found\n");
    }
}

int main(void)
{
    head = (Node *)malloc(sizeof(Node));
    head -> next = head;
    curr = head;
    int opt;
    do
    {
        printf("Enter 1 to book a slot\nEnter 2 to delete a slot\nEnter 3 to display your position in queue\nEnter 4 to display queue\nEnter 5 to exit\n");
        printf("Enter option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                pos();
                break;

            case 4:
                disp();
                break;

            case 5:
                printf("Exiting program\n");
                break;
        }
    }
    while(opt != 5);
}
