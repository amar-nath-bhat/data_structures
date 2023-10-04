#include <stdio.h>
#include <stdlib.h>
//Linear Search
int main()
{
    int a[100], n,j,i, num, flag=0;
    printf("Enter the size of array.\n");
    scanf("%d",&n);
    printf("Enter the elements of the array.\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the element to search.\n");
    scanf("%d",&num);
    for(j=0;j<n;j++){
        if(a[j]==num)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("Element found at %d",j+1);
    else
        printf("Element not found");

return 0;
}
