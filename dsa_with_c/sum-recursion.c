#include<stdio.h>



int sum_ret(int n)
{
    int sum = 0 ;
    if(n==0) return sum;
    sum +=  n+sum_ret(n-1);
    return sum;
}
int main()
{
    int n ;
    printf("enter the value of n");
    scanf("%d",&n);


    int sum = sum_ret(n);
    printf( "sum of given n number of natural number :-  %d" ,sum );
}