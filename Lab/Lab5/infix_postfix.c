#include <stdio.h>
#include <stdlib.h>
#define MAX 20
char stk[20];
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
char peek()
{
    return stk[top];
}
char pop()
{
    if(isEmpty())
        return -1;
    char ch = stk[top];
    top--;
    return(ch);
}

void push(char oper)
{
if(isFull())
    printf("Stack Full!!!!");
else
{
    top++; stk[top] = oper;
}
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
switch (ch)
{
case '+':
case '-': return 1;
case '*':
case '/': return 2;
case '^':
case '%': return 3;
}
return -1;
}

int covertInfixToPostfix(char* expression)
{
    int i, j; char output[20];
    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (checkIfOperand(expression[i])) output[++j] = expression[i];
        else if (expression[i] == '(') push(expression[i]);
        else if (expression[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                    output[++j] = pop();
            if (!isEmpty() && peek() != '(')
                return -1;
            else
            pop();
        }
        else
        {
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                output[++j] = pop();
            push(expression[i]);
        }
    }
while (!isEmpty())
    output[++j] = pop();
output[++j] = '\0';
printf( "%s", output);
}

int main()
{
char expression[] = "a*b+c/d";
covertInfixToPostfix(expression);
return 0;
}