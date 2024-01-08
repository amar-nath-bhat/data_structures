#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left, *right;
};

struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(){
    int data;
    printf("\nEnter data or -1: ");
    scanf("%d",&data);

    if(data==-1)
        return NULL;
    else{
        struct Node* root = createNode(data);
        printf("\nEnter left child of %d: ", root->data);
        root->left = buildTree();
        printf("\nEnter right child of %d: ", root->data);
        root->right = buildTree();
        return root;
    }
}

void traverse(struct Node* root){
    if(root){
        traverse(root->left);
        printf("%d", root->data);
        traverse(root->right);
    }
}

int depth(struct Node* root){
    if(root==NULL)
        return 0;
    
    return depth(root->left) > depth(root->right) ? depth(root->left)+1 : depth(root->right)+1;
}

void printParent(struct Node* root, int target, struct Node* prev){
    if(root){
        printParent(root->left, target, root);
        if(root->data == target)
            printf("Parent of %d is %d", target, prev->data);
        printParent(root->right, target, root);
    }
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

struct Node* inorderSucc(struct Node* root){
    struct Node* temp = root;
    if(temp->right){
        temp=temp->right;
    }else{
        return NULL;
    }
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}

struct Node* search(struct Node* root, int data){
    if(root->data==data)
        return root;
    
    else if(data<root->data){
        root = search(root->left, data);
    }else{
        root = search(root->right, data);
    }
    return root;
}

void delete(struct Node* root, int key){
    struct Node* temp = search(root, key);
    if(temp->left==NULL && temp->right==NULL){
        free(temp);
    }else if(temp->right){
        struct Node* iS = inorderSucc(temp);
        delete(temp, iS->data);
        temp=iS;
    }else if(temp->left){
        struct Node* iS = inorderSucc(temp->left);
        delete(temp->left, iS->data);
        temp=iS;
    }
}

int main(){
    struct Node* root = createNode(5);
    int i;
    // for(i=0; i<10; i++){
    //     if(i==5)
    //         continue;
    //     insert(root, i);
    // }
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);
    // struct Node* temp = search(root, 3);
    // inorderSucc(temp);
    // inorderSucc(root);
    // traverse(root);
    // printParent(root, 3, root);
    // printf("\n%d\n", depth(root));
    delete(root, 3);
    traverse(root);
}