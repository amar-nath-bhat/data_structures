#include <stdio.h>
#include <stdlib.h>
//Selection Sort
int main()
{
    int a[100], n, pass, j, min, t, i;
    printf("Enter the size of array.\n");
    scanf("%d",&n);
    printf("Enter the elements of the array.\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(pass=0;pass<n-1;pass++)
    {
    min=pass;
    for(j=pass+1;j<n;j++)
    {
    if(a[min]>a[j])
        min=j;
    }
    if(min!=pass){
        t=a[min];
        a[min]=a[pass];
        a[pass]=t;
    }
    }
    printf("New sorted array is:\n");
    for(j=0;j<n;j++)
        printf("%d\t",a[j]);


    return 0;
}