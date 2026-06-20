//infix to prefix 
#include<stdio.h>
#include<string.h>
#include<math.h>
int prece(char ch){
    switch(ch){
        case '+': return 1;
        case '-': return -1;
        case '*': return 2;
        case '/': return -2;
    }
}

char ret_char(int t){
    switch(t){
      case 1: return '+';
      case -1: return '-';
      case 2: return '*';
      case -2: return '/';
    }
}

void reverse_string(char *str,int n){
    strrev(str);
    for(int i=0;i<n;i++){
        if(str[i]=='(')
           str[i]=')';
        else if(str[i]==')') 
            str[i]='(';
    }
}

void push(int st[],int val,int *top,int n){
    if(*top==n-1){
        printf("stack is full\n");
    }else{
        st[++(*top)]=val;
    }
}

int pop(int st[],int *top){
    int a=-1;
    if(*top==-1){
        printf("stack is empty\n");
    }else{
        a=st[(*top)--];
    }
    return a;
}

int main(){
    char str[20],ans[20];
    int top=-1,n,indx=0;
    printf("Enter the expression:");
    scanf("%s",str);
    n=strlen(str);
    int st[n];
    reverse_string(str,n);
    for(int i=0;i<n;i++){
        if (str[i]=='(')
            push(st,0,&top,n);
        else if(str[i]==')'){
            while (st[top]!=0){
                int temp=pop(st,&top);
                ans[indx++]=ret_char(temp);
            }
            pop(st,&top);
        }
        else if(str[i]>='a' && str[i]<='z'){
            ans[indx++]=str[i];
        }
        else{
            if(top==-1)
                push(st,prece(str[i]),&top,n);
            else{
               while(fabs(prece(str[i]))<fabs(st[top])){
                   int temp=pop(st,&top);
                   ans[indx++]=ret_char(temp);
               }
               push(st,prece(str[i]),&top,n);
            }
        }
    }
    while(top!=-1){
        int temp=pop(st,&top);
        ans[indx++]=ret_char(temp);
    }
    ans[indx]='\0';
    strrev(ans);
    printf("prefix expression:%s",ans);
    return 0;
}