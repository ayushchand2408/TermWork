#include <stdio.h>


void push(int st[],int val,int *top){
    st[++(*top)]=val;
}

int pop(int st[],int *top){
    if (*top==-1)
     return -1;
    else
     return st[(*top)--];
}

int eval(int a , int b, char ch)
{
    switch(ch){
        case '+': return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;
    }
}

int main()
{
    char  s[20]="12+33/4*3*-5-";
   

    int n=sizeof(s)/sizeof(s[0]);
    int st[n],top = -1;

    for(int i = 0 ; s[i] != '\0' ;i++)
    {
        if(s[i] >= '0' && s[i]<= '9')
           push(st,s[i]-'0',&top);
        
        else{
            int b = pop(st,&top);
            int a = pop(st,&top);
            int res  = eval(a,b,s[i]);
            push(st,res,&top);
        }
    }

   printf("result is : - \n%d",st[top]);

    return 0;
}