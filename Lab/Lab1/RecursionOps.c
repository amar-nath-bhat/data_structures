#include <stdio.h>
#include <stdlib.h>

int search(int a[], int low, int high, int num) {
    if (low <= high) {
        int mid = (high + low)/2;

        if (a[mid] == num) {
            return mid;
        } else if (a[mid] < num) {
            return search(a, mid + 1, high, num);
        } else {
            return search(a, low, mid - 1, num);
        }
    }

    return -1; // Element not found
}

int sort(int a[], int n, int i)
{
    int min, t;
    if (i==n-1)
        return;
    min=i;
    for(int j=i+1;j<n;j++)
    {
        if(a[min]>a[j])
            min=j;
    }
    if(min!=i){
        t=a[min];
        a[min]=a[i];
        a[i]=t;
    }
    sort(a, n, i+1);
}

int multiply(int a, int b){
if (b==0)
    return 0;

return a+multiply(a, b-1);
}

int main() {
    int option;
    printf("Choose the program you want to execute:\n1.Binary Search\n2.Selection Sort\n3.Multiply\n4.Exit\n");
    scanf("%d",&option);
    int a[100], n, i, j, num;
    switch(option){
    case 1: printf("\nBinary Search:\n");
            printf("Enter the size of array.\n");
            scanf("%d",&n);
            printf("Enter the elements of a sorted array.\n");
            for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            printf("Enter the element to search.\n");
            scanf("%d",&num);
            int result = search(a, 0, n - 1, num);

            if (result != -1)
                printf("Element %d found at position %d.\n\n", num, result+1);

            else
                printf("Element %d not found.\n\n", num);

            main();
            break;

    case 2: printf("\nSelection Sort:\n");
            printf("Enter the size of array.\n");
            scanf("%d",&n);
            printf("Enter the elements of the array.\n");
            for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            sort(a, n, 0);
            printf("Sorted array is:\n");
            for(i=0;i<n;i++)
                printf("%d\t",a[i]);
            printf("\n\n");
            main();
            break;

    case 3: printf("\nMultiply 2 numbers:\n");
            int a, b, prod;
            printf("Enter two numbers to multiply:\n");
            scanf("%d%d",&a,&b);
            prod=multiply(a, b);
            printf("Product of %d and %d is: %d\n\n",a,b,prod);
            main();
            break;

    case 4: exit(0);
    }
}
