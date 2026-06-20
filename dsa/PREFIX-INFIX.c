#include <stdio.h>
#include<string.h>
#define SIZE 100
void push(int n,char st[][SIZE],char *ans,int *top){
        strcpy(st[++(*top)],ans);
}

char *pop(int n,char st[][SIZE],int *top){
        return st[(*top)--];
}

int main(){
    char str[20];
    int top=-1,n;
    printf("enter the prefix expression:");
    scanf("%s",str);
    n=strlen(str);
    strrev(str);
    char st[SIZE][SIZE];
    for(int i=0;i<n;i++){
        if(str[i]>='a' && str[i]<='z'){
            char temp[2];
            temp[0]=str[i];
            temp[1]='\0';
            push(n,st,temp,&top);
        }else{
            char op[SIZE]="(";
            char cp[2]=")";
            char temp[2];
            temp[0]=str[i];
            temp[1]='\0';
            char *a=pop(n,st,&top);
            char *b=pop(n,st,&top);
            strcat(op,a);
            strcat(op,temp);
            strcat(op,b);
            strcat(op,cp);
            push(n,st,op,&top);
        }
    }
    printf("infix expression:%s",st[top]);
    return 0;
}  