#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *create(int data)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertend(Node *head, int data)
{
    Node *newnode = create(data);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void display(Node *head)
{
    if (head->next == NULL)
    {
        printf("List Empty\n");
        return;
    }
    Node *curr = head->next;
    printf("List: ");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

Node *union_lists(Node *list1, Node *list2)
{
    Node *start = create(-1);
    Node *temp1 = list1->next;
    Node *temp2 = list2->next;
    Node *result = start;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            insertend(result, temp1->data);
            temp1 = temp1->next;
        }
        else if (temp1->data > temp2->data)
        {
            insertend(result, temp2->data);
            temp2 = temp2->next;
        }
        else
        {
            insertend(result, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        insertend(result, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        insertend(result, temp2->data);
        temp2 = temp2->next;
    }

    return start;
}

Node *intersection_lists(Node *list1, Node *list2)
{
    Node *start = create(-1);
    Node *temp1 = list1->next;
    Node *temp2 = list2->next;
    Node *result = start;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            temp1 = temp1->next;
        }
        else if (temp1->data > temp2->data)
        {
            temp2 = temp2->next;
        }
        else
        {
            insertend(result, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        insertend(result, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        insertend(result, temp2->data);
        temp2 = temp2->next;
    }

    return start;
}

int main()
{
    int n1, n2, data;
    Node *list1 = create(-1);
    printf("Enter no. of nodes: ");
    scanf("%d", &n1);

    while (n1 > 0)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insertend(list1, data);
        n1--;
    }

    Node *list2 = create(-1);
    printf("Enter no. of nodes: ");
    scanf("%d", &n2);

    while (n2 > 0)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insertend(list2, data);
        n2--;
    }

    Node *start = NULL;
    start = union_lists(list1, list2);
    display(start);
    printf("\n");
    start = intersection_lists(list1, list2);
    display(start);
}