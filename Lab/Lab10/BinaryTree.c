#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){

    struct node* root = malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void insertNode(struct node* root, int data){
    struct node* newNode = NULL;
    newNode = createNode(data);
    if(root == NULL){
        printf("Ji i am here!");
        root = newNode;
        return;
    }

    char direction[50];
    printf("Enter the direction to insert with only L & R without spaces: ");
    scanf("%s",direction);
    struct node* curr = root;
    struct node* prev = NULL;
    int i;
    for(i=0; i<strlen(direction)&& curr!=NULL; i++){
        prev = curr;
        if(direction[i] == 'L')
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(curr!=NULL || i!=strlen(direction)){
        printf("Insertion not possible!");
        free(newNode);
        return;
    }

    if(direction[i-1]=='L')
        prev->left = newNode;
    else
        prev->right = newNode;
}

/*
Iterative inorder traversal
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S if not NULL and set current = current->left until current is NULL(repeat)
4) If current is NULL and stack is not empty then
 a) Pop the top item from stack.
 b) Print the popped item,
set current = popped_item->right
 c) Go to step 3.
5) stack is empty then we are done.
*/
void inorderDisp(struct node* root){
    if(root == NULL){
        printf("No tree!");
        return;
    }

    struct Stack *Stack[50];
    int top=-1;

    struct node* curr = root;
    for(;;){
        while(curr!=NULL){
        Stack[++top] = curr;
        curr=curr->left;
        }
        if(top>=0)
            curr  = Stack[top--];
        else
            break;

        printf("%d", curr->data);
        curr=curr->right;
    }
}

/*
Post order iterative
1. Push root to first stack.
2. Loop while first stack is not empty
2.1 Pop a node from first stack and push it to second stack
2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack
*/

void postorderDisp(struct node* root){
    if(root ==NULL)
        return;

    struct node* Stack1[50];
    struct node* Stack2[50];
    int top1 = -1;
    int top2 = -1;
    struct node* popped;
    Stack1[++top1] = root;
    while(top1>=0){
        popped = Stack1[top1--];
        Stack2[++top2] = popped;
        if(popped->left)
            Stack1[++top1] = popped->left;
        if(popped->right)
            Stack1[++top1] = popped->right;
    }
    while(top2>=0){
        popped = Stack2[top2--];
        printf("%d", popped->data);
    }
}

/*
2. Iterative Preorder traversal algorithm
1. Create an empty stack nodeStack and push root node to stack
2. Do following while nodeStack is not empty
a. Pop an item from stack and print it.
b. Push right child of popped item to stack
c. Push left child of popped item to stack
*/

void preorderDisp(struct node* root){
    if(root == NULL)
        return;

    struct node* Stack[50];
    int top=-1;

    Stack[++top] = root;
    struct node* popped;
    while(top>=0){
        popped = Stack[top--];
        printf("%d",popped->data);
        if(popped->right)
            Stack[++top] = popped->right;

        if(popped->left)
            Stack[++top] = popped->left;
    }
}

struct node* findParent(struct node* curr, int data, struct node* prev){
    if(curr!=NULL){
        findParent(curr->left, data, curr);
        if(data == curr->data){
            printf("%d", prev->data);
            return prev;
        }
        findParent(curr->right, data, curr);
    }
}

int depth(struct node* root){
    if(root == NULL)
        return 0;
    int ldepth = depth(root->left);
    int rdepth = depth(root->right);
    if(ldepth>rdepth)
        return ldepth+1;
    else
        return rdepth+1;
}

int printAncestors(struct node* root, int target){
    if(root ==NULL)
        return 0;
    if(root->data == target)
        return 1;
    if(printAncestors(root->left, target) || printAncestors(root->right, target)){
        printf("%d", root->data);
        return 1;
    }
    return 0;
}

int countLeaf(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        int leftLeaves = countLeaf(root->left);
        int rightLeaves = countLeaf(root->right);
        return leftLeaves + rightLeaves;
    }
}

int main(){
    struct node* root = NULL;
    root = createNode(8);
    for(int i=0; i<5; i++){
        insertNode(root, i);
    }
    
    inorderDisp(root);
    printf("\n");
    postorderDisp(root);
    printf("\n");
    preorderDisp(root);
    printf("\n");
    struct node* parent = findParent(root, 3, root);
    printf("\n");
    printf("%d", depth(root));
    printf("\n");
    printAncestors(root, 8);
    printf("\n");
    printf("count of leaf node: %d", countLeaf(root));

}