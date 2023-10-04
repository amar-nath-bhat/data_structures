#include <stdio.h>
#include <stdlib.h>
//Insertion Sort
int main()
{
    int a[100], n, i, pass, j, key;
    printf("Enter the size of array.\n");
    scanf("%d",&n);
    printf("Enter the elements of the array.\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(pass=1;pass<n;pass++)
    {
    key=a[pass];
    for(j=pass-1;j>=0 && a[j]>key;j--)
        a[j+1]=a[j];

        a[j+1]=key;

    }
    printf("New sorted array is:\n");
    for(j=0;j<n;j++)
        printf("%d\t",a[j]);


    return 0;
}