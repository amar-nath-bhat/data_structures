#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    long number;
    char name[100];
    struct node* next;
};

struct node* start = NULL;

void create() {
    long number;
    int n;
    char name[100];
    struct node* newnode, * temp;
    
    printf("Enter the number of records to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));

        while (getchar() != '\n');

        printf("Enter Name: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0'; 

        printf("Enter Phone Number: ");
        scanf("%ld", &number);
        
        strcpy(newnode->name, name);
        newnode->number = number;
        newnode->next = NULL;

        if (start == NULL) {
            start = newnode;
            temp = start;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }
}

void display() {
    struct node* temp;
    temp = start;

    while (temp != NULL) {
        printf("Name: %s\tPhone Number: %ld\n", temp->name, temp->number);
        temp = temp->next;
    }
}

void delete(char name[]) {
    struct node *temp = start, *prev = NULL;
    
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                // If the first node matches, update the start pointer
                start = temp->next;
            } else {
                // Update the previous node's next pointer to skip the current node
                prev->next = temp->next;
            }
            free(temp); // Free the memory of the deleted node
            printf("Name deleted: %s\n", name);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Name not found: %s\n", name);
}

void search(char name[])
{
    struct node *temp;
    temp=start;
    char choice;
    long number;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name found, do you want to update phone number?(Y/n)\n");
            scanf("%c",&choice);
            if(choice=='Y'||choice=='y')
            {
                printf("Enter new number: ");
                scanf("%ld",&number);
                temp->number=number;
                printf("Number updated successfully!!\n");
            }
        }
        temp = temp->next;
    }

    printf("Name not found: %s\n", name);

}

int main() {
    char ch[10];
    create();
    printf("Enter name: ");
    while (getchar() != '\n');
    fgets(ch,sizeof(ch),stdin);
    ch[strlen(ch) - 1] = '\0'; 
    // delete(ch);
    search(ch);
    display();
    return 0;
}
