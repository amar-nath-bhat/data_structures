#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode
{
    int data;
    Tptr leftchild;
    Tptr rightchild;
}TNode;

Tptr root;

int top = -1;
Tptr stack[MAX];

Tptr createNode(int val)
{
    Tptr temp =(Tptr)malloc(sizeof(TNode));
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}

void createTree(int N)
{
    int cData,dIndex;
    char dir[50];
    Tptr previous = NULL,current;

    for(int i=0;i<N;i++)
    {
        printf("Enter data for node %d",i);
        scanf("%d",&cData);
        Tptr temp = createNode(cData);
        //assign root node
        if(!root)
        {
            root = temp;
        }

        else
        {
            printf("Enter direction");
            scanf("%s",dir);
            current = root;
            previous = NULL;
            for(dIndex=0;dir[dIndex]!='\0' && current!=NULL;dIndex++)
            {
                previous = current;
                if(dir[dIndex]=='L'||dir[dIndex]=='l')
                {
                    current = current->leftchild;
                }
                else
                {
                    current = current->rightchild;
                }
            }
            if(current!=NULL||dir[dIndex]!='\0')
            {
                printf("Invalid");
                free(temp);
                return;
            }
            if(dir[dIndex-1]=='L'||dir[dIndex-1]=='l')
            {
                previous->leftchild = temp;
            }
            else
            {
                previous->rightchild = temp;
            }
        }
    }
}

bool isFull()
{
    return top==MAX;
}

bool isEmpty()
{
    return top==-1;
}


void Push(Tptr node)
{
    if(!isFull())
    {
        stack[++top] = node;
    }
}

Tptr Pop()
{
    Tptr ret = NULL;
    if(!isEmpty())
    {
        ret = stack[top--];
    }
    return ret;
}

Tptr peek()
{
    return stack[top];
}


Tptr createRecursive(Tptr root,int value)
{
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->leftchild = createRecursive(root->leftchild, value);
    } else if (value > root->data) {
        root->rightchild = createRecursive(root->rightchild, value);
    }

    return root;
}

void printPostorder(Tptr root)
{
    if (root) {
        printPostorder(root->leftchild);
        printPostorder(root->rightchild);
        printf("%d ",root->data);
    }
}

void printPreorder(Tptr root)
{
    if (root) {
        printf("%d ",root->data);
        printPreorder(root->leftchild);
        printPreorder(root->rightchild);
    }
}

void printInorder(Tptr root)
{
    if (root) {
        printInorder(root->leftchild);
        printf("%d ",root->data);
        printInorder(root->rightchild);
    }
}


int main() {

    root = createRecursive(root,5);
    root = createRecursive(root,3);
    root = createRecursive(root,8);
    root = createRecursive(root,2);
    root = createRecursive(root,4);

    printf("Binary Tree (In-Order): ");
    printInorder(root);
    printf("\n");

    printf("Binary Tree (Pre-Order): ");
    printPreorder(root);
    printf("\n");

    printf("Binary Tree (Post-Order): ");
    printPostorder(root);
    printf("\n");

    return 0;
}
