#include<stdio.h>
#include<string.h>

int palindrome(char str[],int n,int i)
{
    if(i >= n) 
    {
        return 1;
    }
   if(str[i] != str[n])
   {
    return 0;
   }
  
   return palindrome(str,n-1,i+1);
   
}
int main()
{
    char str[100] ;

    printf("enter the vale of string you want to check :- ");
    scanf("%s",str);

    int n  = strlen(str) -1;

    int flag = palindrome(str,n,0);

    if(flag == 1){
        printf("true");
    }
    else{
        printf("false");
    }
}