/*Given an expression string consisting of opening and closing brackets “{“,”}”,”(“,”)”,”[“,”]”,
design an algorithm and a program to check whether this expression has balanced paranthesis or
not.*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int code(char ch){
  switch(ch){
  case '(':
      return 1;
  case ')':
      return -1;
  case '{':
      return 2;
  case '}':
      return -2;
  case '[':
      return 3;
  case ']':
      return -3;
  }

}
void push(char st[],int *top, char val,int n){
    if(*top>=n-1)
       printf("stack is full\n");
    else{
      st[++(*top)]=val;
    }
}

bool isempty(int top){
   if(top==-1)
      return true;
   else
      return false;
}

void pop(int *top){
    if(isempty(*top)){
        printf("stack is empty\n");
    }else{
    (*top)--;
    }
}

void main(){
   char str[50];
   int n,top=-1,flag=1,i;
   printf("enter the string:");
   scanf("%s",str);
   n=strlen(str);
   char st[n];
   for(i=0;i<n;i++){
      if(code(str[i])>0)
          push(st,&top,str[i],n);
      else if(!isempty(top) && code(str[i])+code(st[top])==0)
          pop(&top);
      else 
          flag=0;
   }
   if(flag==1 && isempty(top))
       printf("balanced");
   else
       printf("not balanced");
}