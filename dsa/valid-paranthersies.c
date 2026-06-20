#include <stdio.h>
#include <string.h>

void push(char s[],char ch,int *top){
	s[++(*top)]=ch;
}

void pop(int* top){
	if(*top>-1){
		--(*top);
	}
	else{
		printf("stack is empty!!");
	}
}
int main()
{
    char temp[100];
    int top=-1;
    int size = 0;
    char s[100];
    
    printf("enter the value of string ");
        scanf("%s",temp);
          int n = strlen(temp);
    

        for(int j = 0 ; j<n ; j++) 
        {
            if(temp[j] == '(')
            {
                char ch = temp[j];
                push(s,ch,&top);
            }
            else 
            {
               if (s[top] == '(')
               {
                pop(&top);
                size = size+ 2;
               }
            }
           
        }
    printf("%d",size);
}