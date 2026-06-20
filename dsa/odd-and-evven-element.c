#include <stdio.h>

int main()
{
    int n,sum = 0,j=0,k=0;
    printf("enter the size of array");
    scanf("%d",&n);

    int arr[n], right = n-1;
    printf("enter the element of array");
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < n ; i++)
    {
        sum += arr[i];
        if(arr[i] %2 != 0)
        {
           arr[j] = arr[i]; 
           printf("%d is odd element\n ",arr[j++]);
        }
        else{
            arr[k] = arr[i];
            printf("%d is even element\n ",arr[k++]);
        }
    }
    printf("sum of an given array %d", sum);
}