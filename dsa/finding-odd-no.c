#include<stdio.h>

int main()
{
    int n,result = 0;
    printf("enter the size of array");
    scanf("%d",&n);

    int arr[n];

    printf("enetr the elements of array");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&arr[i]);
        
    }
   
    for(int i = 0 ; i < n ; i++)
    { 
        result = result ^ arr[i];
       
    }
    printf("odd no. %d",result);
}