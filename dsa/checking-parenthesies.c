#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h> 

void push(char st[],char ch,int* top){
	st[++(*top)]=ch;
}

void pop(int* top){
	if(*top>-1){
		--(*top);
	}
	else{
		printf("stack is empty!!");
	}
}

bool isEmpty(int top){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}

int code(char s[],int i)
{ 
	int l,m;
	switch(s[i]){
		case '(':
		l=1;
		break;
		case '{':
		l=2;
		break;
		case '[':
		l=3;
		break;
		case ')':
		m=-1;
		break;
		case '}':
		m=-2;
		break;
		case ']':
		m=-3;
		break;
	}
	if(s[i]=='(' || s[i]=='{'||s[i]=='['){
		return l;
	}
	else{
		return m;
	}
}
 int topof(char s[],int i,int l,int m,int top)
 {
	int flag = 0;

	if(l + m == 0){
       pop(&top);
	}
	else{
		flag = 1;
	}
	return flag;

 }


int main(){
	int n,flag=0;
	printf("enter the size of array");
	scanf("%d",&n);
	    
	char s[n];
	char st[n];
	printf("enter the value of array");
	 scanf("%s",s);
		
	 int l,m,top=-1;
	 for(int i=0;i<n;i++)
	 {
	     if(s[i]=='(' || s[i]=='{'||s[i]=='[')
	     {
           l= code(s,i);
	        push (st,s[i],&top);
	     }
	     else if(s[i]==')' || s[i]=='}'||s[i]==']' && !isEmpty(top))
	     { 
			m = code(s,i);
		    flag =  topof(s,i,l,m,top);
	            
	     }
	     else
	     {
	        printf("Not matched");
	        flag=1;
	        break;
	     }
	 }
	 if(flag==0)
	 {
	    printf("Bracket matched");
	 }
	 else
	 {
	    printf("Not Matched");
	 }

	return 0;
}