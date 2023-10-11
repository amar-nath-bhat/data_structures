#include<stdio.h>
#include<string.h>
#define MAX 50

char stack[MAX];
int top=-1;

int isEmpty()
{
    return top==-1;
}

int isFull()
{
    return top==MAX-1;
}

void push(char item)
{
    if(isFull())
    {
        printf("Stack FUll\n");
        return;
    }
    top++;
    stack[top]=item;
}

char pop()
{
    char popped;
    if(isEmpty())
    {
        printf("Stack Empty");
        return -1;
    }
    popped=stack[top];
    top--;
    return popped;
}

char peek()
{
    return stack[top];
}

int precedence(char sym)
{
    switch (sym)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '%': 
        case '^': return 3;
    }
    return -1;
}

int isOp(char sym)
{
    return (sym=='+'|| sym=='-'||sym=='*'||sym=='/'||sym=='%'||sym=='^');
}

int isAplha(char sym)
{
    return ((sym>='a'&&sym<='z')||(sym>='A'&&sym<='Z'));
}

void postfix(char exp[])
{
    int i, j=-1;
    char output[MAX];

    for(i=0;i<strlen(exp);i++)
    {
        char sym=exp[i];

        if(sym=='(')
            push(sym);
        else if(sym==')')
        {
            while(!isEmpty()&&peek()!='(')
            {
                output[++j]=pop();
            }
            if(!isEmpty()&& peek()!='(')
                return;
            else
                pop();
        }
        else if(isOp(sym))
        {
            while(!isEmpty() && precedence(sym)<=precedence(peek()))
                output[++j]=pop();
            push(sym);
        }
        else if(isAplha(sym))
            output[++j]=sym;

    }
    while(!isEmpty())
        output[++j]=pop();
    output[++j]='\0';
    puts(output);
}

void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void prefix(char exp[])
{
    int i, j=-1;
    char output[MAX];
    for(i=strlen(exp);i>=0;i--)
    {
        char sym=exp[i];

        if(isAplha(sym))
            output[++j]=sym;
        else if(sym==')')
            push(sym);
        else if(sym=='(')
        {
            while(!isEmpty()&&peek()!=')')
                output[++j]=pop();
            if(!isEmpty()&&peek()!=')')
                return;
            else
                pop();
        }
        else if(isOp(sym))
        {
            while(!isEmpty()&&precedence(sym)<precedence(peek()))
                output[++j]=pop();
            push(sym);
        }
    }
    while(!isEmpty())
        output[++j]=pop();
    output[++j]='\0';
    reverseString(output);
    puts(output);

}
int main()
{
    char exp[MAX]="(a+b)*(c-d)";
    prefix(exp);

}