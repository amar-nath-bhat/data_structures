#include <stdio.h>
#include <stdlib.h>
//Bubble Sort
int main()
{
    int a[100], n, i, j, temp;
    printf("Enter the size of array.\n");
    scanf("%d",&n);
    printf("Enter the elements of the array.\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
    for(j=0;j<n-i-1;j++)
    {
    if(a[j]>a[j+1]){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
    }
    }
    }
    printf("New sorted array is:\n");
    for(j=0;j<n;j++)
        printf("%d\t",a[j]);


    return 0;
}