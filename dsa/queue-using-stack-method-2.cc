#include <stdio.h>
#include <stdbool.h>

bool isempty(int top){
    if(top==-1)
        return false;
    else 
        return true;
}
void push(int st[],int val,int *top){
      st[++(*top)]=val;
}
int pop(int st[],int *top){
    int a=-1;
    if(*top==-1){
        printf("queue is empty");
        return a;
    }else{
    a=st[(*top)--];
    }
    return a;

}
void enqueue(int st1[],int *top1,int val,int n){
    if(*top1==n-1){
        printf("queue is full");
    }else{
        push(st1,val,top1);
    }
}
int dequeue(int st1[],int st2[],int *top1,int *top2){
    int a;
    if(*top1==-1&&*top2==-1){
        printf("queue is empty");
    }else{
         while(*top1!=-1){
           a=pop(st1,top1);
           push(st2,a,top2);
    }
    a=pop(st2,top2);
    }
   return a;
}
void display(int st1[],int st2[],int *top1,int *top2){
    int a;
    while(*top1!=-1){
         a=pop(st1,top1);
         push(st2,a,top2);
    }
    for(int i=*top2;i>=0;i--){
        printf("%d ",st2[i]);
    }
    printf("\n");
}
int main(){
    int top1=-1,top2=-1,n,a;
    printf("enter the size:");
    scanf("%d",&n);
    int s1[n],s2[n];
    enqueue(s1,&top1,1,n);
    enqueue(s1,&top1,2,n);
    enqueue(s1,&top1,3,n);
    enqueue(s1,&top1,4,n);
    enqueue(s1,&top1,5,n);
    display(s1,s2,&top1,&top2);
    a=dequeue(s1,s2,&top1,&top2);
    printf("deleted value=%d\n",a);
    a=dequeue(s1,s2,&top1,&top2);
    printf("deleted value=%d\n",a);
    display(s1,s2,&top1,&top2);
    return 0;
}