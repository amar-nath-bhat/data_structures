#include <stdio.h>
#include <stdlib.h>


struct bst
{
        struct bst *lchild;
        int data;
        struct bst *rchild;
};
struct bst *root=NULL;

void display(struct bst *ptr){
        if(ptr){
        display(ptr->lchild);
        printf("%d ",ptr->data);
        display(ptr->rchild);
    }
}
struct bst* minimumKey(struct bst* curr)
{
while(curr->lchild != NULL) curr = curr->lchild;
return curr;
}

// Iterative function to search in subtree rooted at curr & set its parent
// Note that curr & parent are passed by reference
void searchKey(struct bst* curr, int key, struct bst* parent)
{
// traverse the tree and search for the key
while (curr != NULL&& curr->data != key)
{
// update parent node as current node
parent = curr;
// if given key is less than the current node, go to lchild subtree
// else go to rchild subtree
if (key < curr->data) curr = curr->lchild;
else curr = curr->rchild;
}
}

// Function to delete node from a BST
// Function to delete a node from a BST
void deleteNode(struct bst **root, int key) {
    struct bst *parent = NULL;
    struct bst *curr = *root;

    // Search for the key
    while (curr != NULL && curr->data != key) {
        parent = curr;
        if (key < curr->data) {
            curr = curr->lchild;
        } else {
            curr = curr->rchild;
        }
    }

    if (curr == NULL) {
        // Key not found
        return;
    }

    if (curr->lchild == NULL && curr->rchild == NULL) {
        // Case 1: Node has no children
        if (parent) {
            if (parent->lchild == curr) {
                parent->lchild = NULL;
            } else {
                parent->rchild = NULL;
            }
        } else {
            *root = NULL;
        }
        free(curr);
    } else if (curr->lchild && curr->rchild) {
        // Case 2: Node has two children
        struct bst *successor = minimumKey(curr->rchild);
        int val = successor->data;
        deleteNode(&curr->rchild, val);
        curr->data = val;
    } else {
        // Case 3: Node has one child
        struct bst *child = (curr->lchild) ? curr->lchild : curr->rchild;
        if (parent) {
            if (parent->lchild == curr) {
                parent->lchild = child;
            } else {
                parent->rchild = child;
            }
        } else {
            *root = child;
        }
        free(curr);
    }
}

void insert(int ele)
{ struct bst *temp=(struct bst *)(malloc(sizeof(struct bst)));
temp->data=ele; temp->lchild=NULL; temp->rchild=NULL;
if(root==NULL){root=temp;return;}
else
{ struct bst *curr=root,*prev=NULL;
while(curr)
{
prev=curr;
if(temp->data<curr->data) curr=curr->lchild;
else if(temp->data>curr->data) curr=curr->rchild;
else
{ printf("Insertion is not possible. %d already present in BST",ele);
return;
}
}
if(temp->data>prev->data) prev->rchild=temp;
else if(temp->data<prev->data) prev->lchild=temp;
}
return;
}


void search(int ele)
{
if(root==NULL)
    {
        printf("BST is empty");
      return;
     }
struct bst *curr=root;
while(curr!=NULL)
{
if(curr->data==ele)
{ printf("%d found in BST",ele); return; }
else if(curr->data>ele) curr=curr->lchild;
else curr=curr->rchild;
}
printf("%d not found in BST",ele);
}

int main(){


    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);


    printf("BST elements : ");
    display(root);
    printf("\n");


    deleteNode(&root, 30);
    deleteNode(&root, 50);


    printf("BST elements after deletion: ");
    display(root);
    printf("\n");

    search(20);

return 0;
}
