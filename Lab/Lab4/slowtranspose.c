#include<stdio.h>

typedef struct
{
    int row, col, val;
}sparse;

void smatrix(int m, int n, int a[][100], sparse s[])
{
    int i, j, c=0, k=1;
    s[0].row=m;
    s[0].col=n;

    for(i=0;i<m;i++)
    {   for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                s[k].row=i;
                s[k].col=j;
                s[k].val=a[i][j];
                c++;
                k++;
            }
            s[0].val=c;
        }
    }
}

void disp(sparse a[])
{
    printf("row\tcol\tvalue\n");
    for(int i=0;i<=a[0].val;i++)
    {
        printf("%d \t %d \t %d\n",a[i].row, a[i].col, a[i].val);
    }
}

void SlowTranspose(sparse s[])
{
    sparse T[10];
    int coli, arri, Tarri=1;
    T[0].row=s[0].col;
    T[0].col=s[0].row;
    T[0].val=s[0].val;
    for(coli=0;coli<s[0].col;coli++)
    {
        for(arri=1;arri<=s[0].val;arri++)
        {
            if(s[arri].col==coli)
            {
                T[Tarri].row=s[arri].col;
                T[Tarri].col=s[arri].row;
                T[Tarri].val=s[arri].val;
                Tarri++;

            }
        }
    }
    disp(T);
}
int main ()
{
    sparse s[20];
    int i, j, m, n, a[100][100];
    printf("Enter the no. of rows:\n");
        scanf("%d",&m);
    printf("Enter the no. of cols:\n");
        scanf("%d",&n);
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    smatrix(m,n,a,s);
    disp(s);
    SlowTranspose(s);
}