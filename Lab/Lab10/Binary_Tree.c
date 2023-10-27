#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* createNode(int data){
    struct node *n;
    n->data = data;
    n-left=NULL;
    n->right=NULL;
    return n;
}

struct node* insertNode(struct node *root, item){
    struct node *newNode = createNode(item);

    if(root == NULL){
        root = newNode;
        return root;
    }
    
    char direction[20];
    printf("Enter direction to insert the node: ");
    scanf("%s",direction);

    for(int i=0; )

}