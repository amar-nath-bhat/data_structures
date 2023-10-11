#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top=-1;

isEmpty()
{
    return (top==-1);
}

isFull()
{
    return (top==MAX-1);
}

void push(char *item)
{
    if(isFull())
        printf("STack is FUll!");
    else
        strcpy(stack[++top],item);
}

char* pop()
{
    if(isEmpty())
        printf("Stack is EMpty!");
    else
        return stack[top--];
}

int isChar(char sym)
{
    return ((sym>='a'&& sym<='z' )||( sym>='A'&& sym<='Z'));
}

int isOp(char sym)
{
    return (sym=='+'||sym=='-'||sym=='*'||sym=='/'||sym=='%'||sym=='^');
}

void convert(char exp[])
{
    char sym[2];

    for(int i=0;i<strlen(exp);i++)
    {
        if(isChar(exp[i]))
        {
            char sym[2]={exp[i],'\0'};
            push(sym);
        }
        else
        {
            char op1[MAX],op2[MAX];
            char output[MAX];
            strcpy(op2,pop());
            strcpy(op1,pop());
            output[0]=exp[i];
            output[1]='\0';
            strcat(output,op1);
            strcat(output,op2);
            push(output);
        }
    }
    puts(stack[top]);
}

int main()
{
    char exp[MAX];
    scanf("%s",exp);
    convert(exp);
}