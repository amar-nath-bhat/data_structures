#include <stdio.h>
#include <stdlib.h>  

struct Node {
    int coefficient;
    int power;
    struct Node* next;
};

void create(struct Node** start) {  
    struct Node* temp = *start;  
    int num;
    printf("Enter number of terms: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid number of terms.\n");
        return;
    }

    printf("Enter each term with coeff and exp:\n");
    while (num > 0) {
        struct Node* newnode = malloc(sizeof(struct Node));
        scanf("%d %d", &newnode->coefficient, &newnode->power);
        newnode->next = NULL;

        if (*start == NULL) {
            *start = newnode;  
            temp = *start;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        num--;
    }
}

void display(struct Node* start) {
    while (start) {
        printf("%dx%d", start->coefficient, start->power);
        start = start->next;
        if (start) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node* add(struct Node* eqt1, struct Node* eqt2) {
    struct Node* temp1 = eqt1;
    struct Node* temp2 = eqt2;
    struct Node* sum = NULL;
    struct Node* temp_sum = NULL;  

    while (temp1 != NULL || temp2 != NULL) {
        struct Node* newnode = malloc(sizeof(struct Node));

        if (temp1 != NULL && temp2 != NULL) {
            if (temp1->power == temp2->power) {
                newnode->coefficient = temp1->coefficient + temp2->coefficient;
                newnode->power = temp1->power;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->power > temp2->power) {
                newnode->coefficient = temp1->coefficient;
                newnode->power = temp1->power;
                temp1 = temp1->next;
            } else {
                newnode->coefficient = temp2->coefficient;
                newnode->power = temp2->power;
                temp2 = temp2->next;
            }
        } else if (temp1 != NULL) {
            newnode->coefficient = temp1->coefficient;
            newnode->power = temp1->power;
            temp1 = temp1->next;
        } else {
            newnode->coefficient = temp2->coefficient;
            newnode->power = temp2->power;
            temp2 = temp2->next;
        }

        newnode->next = NULL;
        
        if (sum == NULL) {
            sum = newnode;
            temp_sum = sum;
        } else {
            temp_sum->next = newnode;
            temp_sum = newnode;
        }
    }

    return sum;
}

int main() {
    struct Node* equation1 = NULL;
    struct Node* equation2 = NULL;

    create(&equation1);
    printf("Equation 1: ");
    display(equation1);

    create(&equation2);
    printf("Equation 2: ");
    display(equation2);

    struct Node* result = add(equation1, equation2);
    printf("Result: ");
    display(result);

    // Free the allocated memory
    struct Node* current = result;
    while (current) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
