#include<stdio.h>

int power(int x, int n)
{
    int pow = 0;
    if(n!=0){
        pow = x * power(x ,n - 1);
        return pow;
    }
    else{
        return 1;
    }
}

int main()
{
    int x,n;

    printf("enter the no : - ");
    scanf("%d", &x);

    printf("enter it's power :- ");
    scanf("%d",&n);

    int pow = power(x,n);
    
    printf("power :-  %d ",pow);
}
