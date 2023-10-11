#include <stdio.h>
#include <stdlib.h>
int length(char []);
void concate(char [], char []);
int compare(char [], char []);
void insert(char [],char [],int );
void delete_sub(char [],char []);
int main(){
int n,p;
char a[100], b[100];
printf("Choose the operation to perform:\n1.Find length of string\n2.Concatenation of STring\n3.Comparison of String\n4.Insert substring\n5.Delete substring\n6.Exit\n");
scanf("%d",&n);
switch(n){
case 1: printf("\nFinding length of the string....\n");
        printf("Enter the string:\n");
        scanf("%s",a);
        int len=length(a);
        printf("\nLength of the string is %d\n\n", len);
        main();
        break;

case 2: printf("\nConcatenation of string....\n");
        printf("Enter the string 1:\n");
        scanf("%s",a);
        printf("Enter the string 2:\n");
        scanf("%s",b);
        concate(a, b);
        main();
        break;

case 3: printf("\nComparison of string....\n");
        printf("Enter the string 1:\n");
        scanf("%s",a);
        printf("Enter the string 2:\n");
        scanf("%s",b);
        compare(a, b);
        main();
        break;

case 4: printf("\nInsertion of substring....\n");
        printf("Enter the main string:\n");
        scanf("%s",a);
        printf("Enter the sub-string to be inserted:\n");
        scanf("%s",b);
        printf("Enter the position to be inserted:\n");
        scanf("%d",&p);
        insert(a, b, p);
        printf("String after insertion:\n%s\n\n", a);
        main();
        break;

case 5: printf("\nDeletion of substring....\n");
        printf("Enter the main string:\n");
        scanf("%s",a);
        printf("Enter the sub-string to be deleted:\n");
        scanf("%s",b);
        delete_sub(a, b);
        printf("String after deletion:\n%s\n\n", a);
        main();
        break;

case 6: exit(0);
}
}

int length(char str[]){
int i;
for(i=0;str[i]!='\0';i++);
return i;
}

void concate(char s1[], char s2[]){
char res[100];
int i, j;
for(i=0;s1[i]!='\0';i++)
    res[i]=s1[i];
j=0;
while(s2[j]!='\0')
    res[i++]=s2[j++];
res[i]='\0';
printf("\nNew String is:\n%s\n\n",res);
}

int compare(char s1[], char s2[]){
int c=0;
    while(s1[c]==s2[c]){
            if(s1[c]=='\0'&&s2[c]=='\0'){
                printf("\nEqual Strings\n\n");
                return 0;
                break;
            }
            c++;
        }
    if(s1[c]!=s2[c]){
            if(s1[c]<s2[c]){
                printf("\nUnequal Strings\n\n");
                return -1;
            }
            else {
                printf("\nUnequal Strings\n\n");
                return 1;
        }
    }
}

void insert(char s1[], char s2[], int p)
{
    int l1 = length(s1);
    int l2 = length(s2);
    if (p < 0 || p > l1) {
        printf("Invalid position to insert!\n");
        return;
    }
    for (int i = l1; i >= p-1; i--) {
        s1[i + l2] = s1[i];
    }
    for (int i = 0; i < l2; i++) {
        s1[p -1 + i] = s2[i];
    }
    s1[l1 + l2] = '\0';
}

// void delete_sub(char s1[], char s2[])
// {
//     int l1,l2,temp,i,j,chk=0;
//     l1=length(s1);
//     l2=length(s2);
//     for(i=0; i<l1; i++)
//     {
//       temp = i;
//       for(j=0; j<l2; j++)
//       {
//          if(s1[i]==s2[j])
//             i++;
//       }
//       chk = i-temp;
//       if(chk==l2)
//       {
//          i = temp;
//          for(j=i; j<(l1-l2); j++)
//             s1[j] = s1[j+l2];
//          l1 = l1-l2;
//          s1[j]='\0';
//         }
//     }
// }

void delete_sub(char s1[], char s2[]) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i, j, k;

    for (i = 0; i <= l1 - l2; i++) {
        for (j = 0; j < l2 && s1[i + j] == s2[j]; j++);
        
        if (j == l2) {
            for (k = i; k < l1 - l2; k++) {
                s1[k] = s1[k + l2];
            }
            s1[k] = '\0'; 
            l1 -= l2;    
            i--;         
        }
    }
}