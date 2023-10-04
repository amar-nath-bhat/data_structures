#include <stdio.h>
#include <stdlib.h>
//Additional 1 max(A,B)
int main()
{
    int a[100][100], b[100][100], c[100][100], m, n, p, q, i, j;
    printf("Enter no. of rows and columns of matrix A:\n");
    scanf("%d%d",&m,&n);
    printf("Enter elements of matrix A:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter no. of rows and columns of matrix B:\n");
    scanf("%d%d",&p,&q);
    printf("Enter elements of matrix B:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            scanf("%d",&b[i][j]);
    }

    if(m==p && n==q)
    {
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        if(a[i][j]>b[i][j])
            c[i][j]=a[i][j];
        else
            c[i][j]=b[i][j];
        }
      }
    }
    printf("Matrix C is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d\t",c[i][j]);
            printf("\n");
    }
return 0;
}