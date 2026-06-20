/*Design an algorithm and a program to implement stack using array. The program should
implement following stack operations:
a) Create() - create an empty stack
b) Push(k) - push an element k into the stack
c) Pop() - pop an element from the stack snd return it
d) IsEmpty() - check if stack is empty or not
e) Size() - finds the size of the stack
f) Print() - prints the contents of stack*/
#include<stdio.h>
void push(int st[],int n,int *top,int x){
	if((*top)>n){
		printf("STACK IS FULL......\n");
	}
	else{
		(*top)++;
		st[*top]=x;
	}
}
void display(int st[],int *top){
	for(int i=*top;i>=0;i--){
		printf("%d\n",st[i]);
	}
}
int pop(int st[],int *top){
	int v;
	if(*top==-1){
		printf("STACK IS EMPTY.......\n");
		return -1;
	}
	else{
		v=st[*top];
		(*top)--;
	}
	return v;
}
void isempty(int *top){
	if(*top==-1){
		printf("STACK IS EMPTY\n");
	}
	else{
		printf("STACK IS NOT EMPTY\n");
	}
}
int main(){
	int n;
	printf("Enter the maximum size of the stack :");
	scanf("%d",&n);
	int st[n];
	int top=-1;
	
	int value;
	for(int i=0;i<n;i++){
		printf("Enter the value you want to push : ");
		scanf("%d",&value);
		push(st,n,&top,value);
	}
	printf("ELEMENTS IN THE STACK .............\n");
	display(st,&top);
	int removed=pop(st,&top);
	printf("poped item is :%d\n",removed);
	printf("After pop operation .............\n");
	display(st,&top);
	printf("size of the stack :%d\n",top+1);
    isempty(&top);
	
}