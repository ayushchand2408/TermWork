#include <stdio.h>

int main()
{
    int n,variable , left = 0,result = 0;
    printf("enter the size of array");
    scanf("%d",&n);

    int arr[n], right = n-1;
    printf("enter the element of array");
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to search in array");
    scanf("%d",&variable);
    while (left <= right)
    {
        int mid = left + ((right - left)/2);

        if (arr[mid] == variable){
         result = mid;
         break;
        }
        else if(arr[mid] < variable)
        {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if(result != 0)
    {
        printf("element found at index %d\n",result);
    }
    else{
        printf("element not find");
    }
    

}