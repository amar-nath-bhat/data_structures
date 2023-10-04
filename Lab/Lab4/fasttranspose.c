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

void FastTranspose(sparse s[])
{
    sparse T[10];
    int rt[10], sp[10], arri, Tarri, i, Tindex;
    for(i=0;i<s[0].col;i++) rt[i]=0;
    for(arri=1;arri<=s[0].val;arri++)
        rt[s[arri].col]++;
    sp[0]=1;
    for(i=1;i<s[0].col;i++)
        sp[i]=sp[i-1]+rt[i-1];
    T[0].row=s[0].col;
    T[0].col=s[0].row;
    T[0].val=s[0].val;
    for(arri=1;arri<=s[0].val;arri++)
    {
        Tindex=sp[s[arri].col]++;
        T[Tindex].row=s[arri].col;
        T[Tindex].col=s[arri].row;
        T[Tindex].val=s[arri].val;
    }
    disp(T);
}
int main ( )
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
    printf("Array representation of sparse matrix is:\n");
    disp(s);

    printf("\nFast Transpose of sparse matrix is:\n");
    FastTranspose(s);
}