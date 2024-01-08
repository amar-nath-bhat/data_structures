// Menu driven program where
// 1) create a stack of nodes(binary tree nodes) with push, pop and display functionality.
// Display shows stack ka top content at very step i.e. everytime we push something into stack and it also should also print the address of the node
// 2) create a binary tree of a postfix expression using the stack i.e. expression tree and display inorder i.e. infix
// 3) display preorder i.e.prefix
// 4) exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* left, *right;
};

struct Node* createNode(char data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* stack[10];
int top=-1;

void push(struct Node* newNode){
    if(top>10){
        printf("cannot add node into stack! Stack Full");
        return;
    }
    stack[++top] = newNode;
    display();
}

struct Node* pop(){
    if(top!=-1){
        struct Node* popped = stack[top--];
        return popped;
    }
    return NULL;
}

void display(){
    struct Node* disp = stack[top];
    inorder(disp);
    printf("\n");
}

void inorder(struct Node* root){
    if(root){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}


void preorder(struct Node* root){
    if(root){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int isOp(char ch){
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='%');
}

struct Node* buildexpTree(){
    char exp[20]; int i;
    printf("Enter a postfix expression: ");
    scanf("%s",exp);
    for(i=0; i<strlen(exp)-1;i++){
        char ch = exp[i];
        // printf("%c", ch);
        struct Node *pop1, *pop2, *newNode;
        if(isOp(ch)){
            newNode=createNode(ch);
            pop2=pop();
            pop1=pop();
            newNode->left =pop1;
            newNode->right=pop2;
            push(newNode);
        }
        else(push(createNode(ch)));
    }
    struct Node* root = createNode(exp[i]);
    root->right = pop();
    root->left = pop();
    return root;
}


int main(){
   struct Node* root = buildexpTree();
   inorder(root);
   printf("\n");
   preorder(root);
}