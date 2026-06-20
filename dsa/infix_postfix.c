#include <stdio.h>
#include <string.h>
#include <math.h>
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

void push(int st[],int val,int *top){
    st[++(*top)]=val;
}

int pop(int st[],int *top){
    if (*top==-1) return -1;
    else return st[(*top)--];
}

int main(){
    char str[25],ans[25];
    int len,ind=0,top=-1;
    printf("enter the exprssion:");
    scanf("%s",str);
    len=strlen(str);
    int st[len];
    for(int i=0;i<len;i++){
        if(str[i]=='('){
           push(st,0,&top);
        }else if(str[i]>='a'&&str[i]<='z'){
            ans[ind++]=str[i];
        }else if(str[i]==')'){
            while(st[top]!=0){
                int t=pop(st,&top);
                ans[ind++]=ret_char(t);
            }
            pop(st,&top);
        }else{
            if(top==-1){
                push(st,prece(str[i]),&top);
            }else{
                while(fabs(prece(str[i]))<=fabs(prece(st[top]))){
                    int i=pop(st,&top);
                    ans[ind++]=ret_char(i);
                }
                push(st,prece(str[i]),&top);
            }
        }
    }
    while(top!=-1){
        int i=pop(st,&top);
        ans[ind++]=ret_char(i);
    }
    ans[ind]='\0';
    printf("postfix expression =%s",ans);
    return 0;
}