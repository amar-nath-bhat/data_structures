#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL)
        exit(0);
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root; 
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void search(struct Node* root, int ele){
    if(root==NULL){
        printf("BST is empty");
        return;
    }
    struct Node* curr=root;
    while(curr!=NULL){
        if(curr->data==ele){ 
            printf("%d found in BST",ele); 
            return; 
        }
        else if(curr->data>ele) 
            curr=curr->left;
        else 
            curr=curr->right;
    }
    printf("%d not found in BST",ele);
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    deleteNode(root, 60);
    printf("\n");
    inorder(root);
    printf("\n");
    search(root, 20);
    printf("\n");
    search(root, 60);
    printf("\n");
}
