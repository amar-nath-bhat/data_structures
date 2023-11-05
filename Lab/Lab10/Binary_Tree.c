#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

void createNode(struct node* root, int data){
    root->data = data;
    root->left=NULL;
    root->right=NULL;
}

// void insertNode(struct node *root, int item){
//     struct node *newNode=NULL;
//     createNode(newNode, item);

//     if(root == NULL){
//         root = newNode;
//         return;
//     }
    
//     char direction[20];
//     printf("Enter direction to insert the node: ");
//     scanf("%s",direction);
//     struct node *prev, *curr;
//     prev=NULL;
//     curr=root;
//     int i;
//     for(i=0; i<strlen(direction)&&curr!=NULL;i++){
//         if(direction[i] = 'L')
//             curr=curr->left;
//         else
//             curr=curr->right;
//     }
//     if(curr!=NULL || i!=strlen(direction)){
//         printf("Insertion not possible!");
//         free(newNode);
//         return;
//     }

//     if(direction[i-1]=='L')
//         prev->left=newNode;
//     else
//         prev->right=newNode;
// }

// void inorderDisp(struct node* root){
//     if(root == NULL){
//         printf("No tree!");
//         return;
//     }

//     struct Stack *Stack[50];
//     int top=-1;

//     struct node* curr = root;
//     for(;;){
//         while(curr!=NULL){
//         Stack[++top] = curr;
//         curr=curr->left;
//         }
//         if(top>=0)
//             curr  = Stack[top--];
//         else
//             break;

//         printf("%d", curr->data);
//         curr=curr->right;
//     }
// }

int main()
{
    struct node* root;
    createNode(root, 8);
   
}