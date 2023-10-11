#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int stk[20];
int top = -1;

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int peek()
{
    return stk[top];
}
int pop()
{
    if(isEmpty())
        return -1;
    int ch = stk[top];
    top--;
    return(ch);
}

void push(int oper)
{
if(isFull())
    printf("Stack Full!!!!");
else
{
    top++; stk[top] = oper;
}
}

void sort(int* arr, int n)
{
    int i, a[20], j=-1;
    for(i=0; i<n; i++)
    {
        int num=arr[i];
        if(isEmpty())
            push(num);
        else if(num<peek())
        {
            while(num<peek())
            {
                a[++j]=pop();
            }push(num);
            while(j>=0)
            {
                push(a[j]);
                j--;
            }
        }
        else
            push(num);
    }

}

int main()
{
    int arr[]={55,1,88,3,9,23,1000};
    sort(arr,7);
    for(int i=0;i<7;i++)
        printf("%d ",stk[i]);
}