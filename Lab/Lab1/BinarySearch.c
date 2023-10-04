#include <stdio.h>
#include <stdlib.h>
//Binary Search
int main()
{
    int a[100], n,j,i, num, mid, low, high, flag=0;
    printf("Enter the size of array.\n");
    scanf("%d",&n);
    printf("Enter the elements of the array.\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the element to search.\n");
    scanf("%d",&num);
    low=0; high=n-1;

    while(low<=high)
    {
    mid=(low+high)/2;
    if(a[mid]==num)
        {flag=1;break;}
    else if (num<a[mid])
        high=mid-1;
    else
        low=mid+1;
    }
    if(flag)
        printf("Element found at %d",mid+1);
    else
        printf("Element not found");

    return 0;
}
