#include<stdio.h>
void toh(int n ,char form ,char to,char aux)
{
    if(n == 0) return;
    toh(n-1,form , aux,to);

    printf("%c -> %c \n",form,to);
    toh(n-1,aux,to,form);
}

int main()
{
    int n = 4;
    toh(n , 'A' , 'B','C');
}