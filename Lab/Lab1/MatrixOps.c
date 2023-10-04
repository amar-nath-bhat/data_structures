#include <stdio.h>
#include <stdlib.h>
//Additional 3
int scan(int a[][100], int x, int y){
int i, j;
printf("Enter elements of the matrix:\n");
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            scanf("%d",&a[i][j]);
    return 0;
}

void add(int a[][100], int b[][100], int rows, int cols){
int i, j, sum[100][100];

    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            sum[i][j]= a[i][j] + b[i][j];
    printf("Sum is:\n");
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++)
                printf("%d\t",sum[i][j]);
            printf("\n");
        }
}

void multiply(int a[][100], int b[][100], int row1, int col1, int row2, int col2){
    int i, j, k, prod[100][100];
        for(i=0;i<row1;i++){
            for(j=0;j<col2;j++)
            {
                prod[i][j]=0;
                for(k=0;k<col1;k++)
                    prod[i][j]=prod[i][j]+a[i][k]*b[k][j];
            }
        }
        printf("\nProduct is:\n");
        for(i=0;i<row1;i++){
            for(j=0;j<col2;j++)
                printf("%d\t",prod[i][j]);
            printf("\n");
            }
        printf("\n");
}
int magicsquare(int a[][100], int m){
    int i, j, sum=0, rowsum, colsum, dsum1=0, dsum2=0;
        for(i=0;i<m;i++)
            sum+=a[0][i];

        for(i=0;i<m;i++){
            rowsum=0;colsum=0;
            for(j=0;j<m;j++){
                rowsum+=a[i][j];
                colsum+=a[j][i];
                }
            if(rowsum!=sum || colsum!=sum)
                return 0;
        }

        for(i=0;i<m;i++){
            dsum1+=a[i][i];
            dsum2+=a[i][m-1-i];
            }
        if(dsum1!=sum || dsum2!=sum)
            return 0;

    return 1;
}

int main()
{   int option;
    printf("Select matrix operation:\n1.Matrix Addition\n2.Matrix Multiplication\n3.Magic Square Check\n4.Exit\n\n");
    scanf("%d",&option);
    int a[100][100], b[100][100], m, n, p, q;
    switch(option)
    {
        case 1: printf("Matrix Addition:\n");
                printf("Enter no. of rows and columns of matrix A:\n");
                scanf("%d%d",&m,&n);
                scan(a, m, n);
                printf("\nEnter no. of rows and columns of matrix B:\n");
                scanf("%d%d",&p,&q);
                scan(b, p, q);
                if(m==p && n==q)
                    add(a, b, m, n);
                else
                    printf("Cannot Add the matrices.\n\n");
                main();
                break;

        case 2: printf("Matrix Multiplication:\n");
                printf("Enter no. of rows and columns of matrix A:\n");
                scanf("%d%d",&m,&n);
                scan(a, m, n);
                printf("Enter no. of rows and columns of matrix B:\n");
                scanf("%d%d",&p,&q);
                scan(b, p, q);
                if(n!=p)
                    printf("Cannot multiply matrices:\n\n");
                else
                    multiply(a, b, m, n, p, q);
                main();
                break;

        case 3: printf("Magic Square Check:\n");
                printf("Enter the order of the square matrix:\n");
                scanf("%d",&m);
                scan(a, m, m);
                if(magicsquare(a, m))
                    printf("Entered Matrix is a Magic Square\n\n");
                else
                    printf("Entered Matrix is not a Magic Square\n\n");
                main();
                break;
        }
    return 0;
}