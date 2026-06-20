#include<stdio.h>
#include<string.h>

void rev(char str[] , int n)
{
    char st1[n];
    int i =  0;
    
    if( n == -1 ) return ;
    st1[i] = str[n];
    printf("%c",st1[i]);
    i++;
    return rev(str,n-1);
    
}
int main()
{
    char str[100],temp[100];
 

    printf("enter the value of string :- ");
    scanf(" %s",str);
    
    int n = strlen(str);
    
    rev(str , n);

   
}