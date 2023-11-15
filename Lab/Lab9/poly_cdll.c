// Write a program to multiply two polynomials using circular doubly linked list with
// header node.

/*Write a menu driven program to:
i) Insert an element into a doubly linked circular list
ii) Delete an element from a doubly linked circular list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int power;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int coeff, int power){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->prev = newNode->next = newNode;
    return newNode;
}

void createEqt(struct Node* eqt, int n){
    if(n==0){
        return;
    }
    struct Node *temp = eqt, *newNode=NULL;
    while(n>0){
        int coeff, power;
        printf("Enter coeff with power: ");
        scanf("%d %d", &coeff, &power);
        newNode = createNode(coeff, power);
        temp->next = newNode;
        newNode->prev=temp;
        temp=temp->next;
        n--;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = eqt;
    eqt->prev = newNode;

}

void display(struct Node* start) {
    struct Node* temp = start->next;
    while (temp!=start) {
        printf("%dx%d", temp->coeff, temp->power);
        temp = temp->next;
        if (temp!=start) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node* insertNode (struct Node* start, struct Node* newNode){
    struct Node* temp = start->prev;
    if(start==NULL){
        return newNode;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = start;
    start->prev = newNode;
    return start;
}

struct Node* multiply(struct Node* eqt1, struct Node* eqt2){
    struct Node* result = createNode(0,0), *temp1 = eqt1->next, *temp2 = eqt2->next;

    while(temp1 != eqt1){
        temp2 = eqt2->next;
        while(temp2 != eqt2){
            int coeff, power, c=0;
            coeff = temp1->coeff * temp2->coeff;
            power = temp1->power + temp2->power;
            struct Node* newNode = createNode(coeff, power), *temp3=result->next;
            while(temp3!=result){
                if(temp3->power == newNode->power){
                    temp3->coeff += newNode->coeff;
                    c = 1;
                    break;
                }
                temp3=temp3->next;
            }
            if(!c)
                result = insertNode(result, newNode);
            
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return result;
}
struct Node* add(struct Node* eqt1, struct Node* eqt2) {
    struct Node* temp1 = eqt1->next;
    struct Node* temp2 = eqt2->next;
    struct Node* sum = createNode(0, 0);
    struct Node* temp_sum = createNode(0, 0);  

    while (temp1 != eqt1 || temp2 != eqt2) {
        struct Node* newnode = malloc(sizeof(struct Node));

        if (temp1 != eqt1 && temp2 != eqt2) {
            if (temp1->power == temp2->power) {
                newnode->coeff = temp1->coeff + temp2->coeff;
                newnode->power = temp1->power;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->power > temp2->power) {
                newnode->coeff = temp1->coeff;
                newnode->power = temp1->power;
                temp1 = temp1->next;
            } else {
                newnode->coeff = temp2->coeff;
                newnode->power = temp2->power;
                temp2 = temp2->next;
            }
        } else if (temp1 != eqt1) {
            newnode->coeff = temp1->coeff;
            newnode->power = temp1->power;
            temp1 = temp1->next;
        } else {
            newnode->coeff = temp2->coeff;
            newnode->power = temp2->power;
            temp2 = temp2->next;
        }

        newnode->next = sum;
        
        if (sum->next == sum) {
            sum->next = newnode;
            temp_sum = sum->next;
            // printf("1");
        } else {
            temp_sum->next = newnode;
            temp_sum = newnode;
            // printf("2");
        }
    }

    return sum;
}

int main(){
    struct Node* start1 = createNode(0, 0);
    struct Node* start2 = createNode(0, 0);
    createEqt(start1, 3);
    createEqt(start2, 3);
    display(start1);
    display(start2);
    struct Node* result = add(start1, start2);
    display(result);

    free(start1);
    free(start2);
    free(result);
}
