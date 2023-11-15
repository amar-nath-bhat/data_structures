#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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


struct Node* copyTree(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* destination = createNode(root->data);
    destination->left = copyTree(root->left);
    destination->right = copyTree(root->right);

    return destination;
}

int main() {
    struct Node* root = NULL;
    root = buildTree();
    struct Node* destination = copyTree(root);

    printf("Root tree (in-order traversal): ");
    inorder(root);
    printf("\n");

    printf("Destination tree (in-order traversal): ");
    inorder(destination);
    printf("\n");

    return 0;
}

