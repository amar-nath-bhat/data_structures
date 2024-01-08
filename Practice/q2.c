// DDL-output
// 1. List : 1 2 3 4 5 - input 
// Display the same 
// 2. Remove from nth posirion from rhe end of list 
// Postion 2 output : 1 2 3 5 
// 3. Make second list to embed on the postuon of frist list
// Second list -1 4 5 6 
// Postion 2 from the end 
// 1 2 3 1 4 5 6 5 merged list 
// 4. delete duplicate
// 2 3 4 6 
// 5. Bst create and display 
//                   2
//                     \
//                      3
//                        \
//                         4
//                           \
//                             6

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct TreeNode
{
    int data;
    struct TreeNode* left, *right;
}TreeNode;

Node* create(int data){
    Node* newnode = malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void insertend(Node* head, int data){
    Node* newnode = create(data);
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void display(Node* head){
    if(head->next==NULL){
        printf("List Empty\n");
        return;
    }
    Node* curr=head->next;
    printf("List: ");
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

void merge(Node* s1, Node* s2, int pos){
    Node* temp =s1->next, *temp2=s2->next;
    while(pos>0){
        temp=temp->next;
        pos--;
    }
    while(temp2->next){
        temp2=temp2->next;
    }
    temp2->next = temp->next;
    temp->next->prev = temp2;
    temp->next = s2->next;
    s2->next->prev = temp;
}

void removeFromEnd(Node* start, int pos){
    if(start->next==NULL)
        return;
    
    Node* curr = start;
    while(curr->next){
        curr=curr->next;
    }
    while(pos>1){
        curr=curr->prev;
        pos--;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
}

Node* deleteDup(Node* start){
    Node* temp = start->next, *temp2 = start->next;;
    int a[10];
    for(int i=1; i<10; i++){
        a[i] = 0;
    }
    while(temp){
        a[temp->data]++;
        temp=temp->next;
    }
    Node* res = create(-1);
    while(temp2){
        if(a[temp2->data] ==1)
            insertend(res, temp2->data);
        temp2=temp2->next;
    }
    return res;
}

TreeNode* bst(TreeNode* root, int data) {
    if (root == NULL) {
        TreeNode* newNode = malloc(sizeof(TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    } else {
        if (data < root->data)
            root->left = bst(root->left, data);
        else if (data > root->data)
            root->right = bst(root->right, data);
    }
    return root; // don't forget to return the updated root
}

void inorder(TreeNode* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

int main(){
    Node* start = create(-1);
    insertend(start, 1);
    insertend(start, 2);
    insertend(start, 3);
    insertend(start, 4);
    insertend(start, 5);
    removeFromEnd(start, 2);
    // display(start);

    Node* start1 = create(-1);
    insertend(start1, 1);
    insertend(start1, 4);
    insertend(start1, 5);
    insertend(start1, 6);
    // display(start1);

    merge(start, start1, 2);
    display(start);
    // // printf("\n");

    Node* res = deleteDup(start);
   
    display(res);
    
    TreeNode* root = NULL;

    Node* temp = res->next;
    while(temp){
        root=bst(root, temp->data);
        temp=temp->next;
    }
    inorder(root);

}