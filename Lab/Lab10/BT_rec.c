// 2. Write a recursive function to i) Create a binary tree and ii) print a binary tree
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left, *right;
};

struct Node* createNode(int data){

    struct Node* root = malloc(sizeof(struct Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct Node* buildTree() {
    int data;
    printf("Enter data (or -1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; // No node
    } else {
        struct Node* root = createNode(data);
        printf("Enter left child of %d\n", data);
        root->left = buildTree();  // Recursively build left subtree
        printf("Enter right child of %d\n", data);
        root->right = buildTree(); // Recursively build right subtree
        return root;
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main()
{
    struct Node* start = NULL;
    start = buildTree();
    inorder(start);
    return 0;
}
