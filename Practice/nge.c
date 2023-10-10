//Next Greater Element is the largest element on the right of the given element.

#include <stdio.h>
#define MAX 20

int stack[MAX];
int top=-1;

int isEmpty()
{
    return top==-1;
}

int isFull()
{
    return top==MAX-1;
}

void push(int item)
{
    if(isFull())
    {
        printf("Stack FUll\n");
        return;
    }
    top++;
    stack[top]=item;
}

int pop()
{
    int popped;
    if(isEmpty())
    {
        printf("Stack Empty");
        return -1;
    }
    popped=stack[top];
    top--;
    return popped;
}

void NGE(int *arr)
{
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(arr[j]>arr[i])
            {
                push(arr[j]);
                break;
            }
        }
        if(top<i)
            push(-1);
    }
}

void display(int *arr)
{
    printf("Element\tNGE\n");
    for(int i=0;i<=top;i++)
    {
        printf("%d\t%d\n",arr[i],stack[i]);
    }
}
int main()
{
    int arr[10];
    printf("Enter the array elements: ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    NGE(arr);
    display(arr);

}