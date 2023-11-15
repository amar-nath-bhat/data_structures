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

int isEqual(struct Node* tree1, struct Node* tree2){
    return((!tree1&&!tree2) || (tree1&&tree2 && tree1->data == tree2->data) && (isEqual(tree1->left, tree2->left) && isEqual(tree1->right, tree2->right)));
}


int main()
{
    struct Node* start1 = NULL;
    start1 = buildTree();
    inorder(start1);
    struct Node* start2 = NULL;
    start2 = buildTree();
    inorder(start2);
    printf("Is Equal: %d",isEqual(start1, start2));
    return 0;
}
