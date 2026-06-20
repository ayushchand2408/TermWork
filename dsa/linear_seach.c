#include <stdio.h>

int main()
{
    int n,variable , flag = 0;
    printf("enter the size of array");
    scanf("%d",&n);

    int arr[n];
    printf("enter the element of array");
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to search in array");
    scanf("%d",&variable);
    for(int i = 0; i < n ; i++)
    {
       if(arr[i] == variable)
       {
        printf("element found at index : %d" , i );
        flag = 0;
        break;
       }
       else{
        flag = 1;
       }
       
    }
    if(flag == 1)
    {
        printf("element not find");
    }
}