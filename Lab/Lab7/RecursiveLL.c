#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *recursive_create(struct node* start, int n) {
    if (n <= 0) {
        return start;
    }

    int data;
    printf("Enter Data: ");
    scanf("%d", &data);

    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        struct node* current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }

    return recursive_create(start, n - 1);
}

void recusrive_traverse(struct node* start)
{
    struct node* temp = start;
    if(temp==NULL)
    {
        printf("NULL\n");
        return;
    }
    
    printf("%d -> ",temp->data);
    return recusrive_traverse(temp->next);
}

int main() {
    struct node* start = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    start = recursive_create(start, n);
    recusrive_traverse(start);
    return 0;
}
