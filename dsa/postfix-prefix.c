//postfix to prefix


#include <stdio.h>
#include<string.h>
void push(int n,char st[][n],char *ans,int *top){
        strcpy(st[++(*top)],ans);
}

char *pop(int n,char st[][n],int *top){
        return st[(*top)--];
}
int main(){
    char str[20];
    int top=-1,n;
    printf("Enter the postfix expression:");
    scanf("%s",str);
    n=strlen(str);
    char st[n][n];
    for(int i=0;i<n;i++){
        if(str[i]>='a' && str[i]<='z'){
            char temp[20];
            temp[0]=str[i];
            temp[1]='\0';
            push(n,st,temp,&top);
        }
        else{
            char ans[20];
            ans[0]=str[i];
            ans[1]='\0';
            char *b=pop(n,st,&top);
            char *a=pop(n,st,&top);
            strcat(ans,a);
            strcat(ans,b);
            push(n,st,ans,&top);
        }
    }
    printf("prefix expression:%s",st[top]);
}