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

int areMirrors(struct Node* root1, struct Node* root2) {

    if (root1 == NULL && root2 == NULL) {
        return 1;
    }


    if (root1 == NULL || root2 == NULL) {
        return 0;
    }


    if (root1->data != root2->data) {
        return 0;
    }


    int leftMirrorsRight = areMirrors(root1->left, root2->right);
    int rightMirrorsLeft = areMirrors(root1->right, root2->left);


    return leftMirrorsRight && rightMirrorsLeft;
}

int main() {

    struct Node* start1 = NULL;
    start1 = buildTree();
    inorder(start1);
    struct Node* start2 = NULL;
    start2 = buildTree();
    inorder(start2);


    if (areMirrors(start1, start2)) {
        printf("The two trees are mirrors of each other.\n");
    } else {
        printf("The two trees are not mirrors of each other.\n");
    }

    return 0;
}
