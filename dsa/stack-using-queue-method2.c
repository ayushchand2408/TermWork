//implementation of stack : push-optimal and pop-costly

#include <stdio.h>
void enqueue(int q[],int *f,int *r,int val){
    q[++(*r)]=val;
    if(*f==-1)
       *f=0;
}
void push(int q1[],int *f1,int *r1,int val,int n){
    if(*r1==n-1){
        printf("stack is full\n");
    }else{
        enqueue(q1,f1,r1,val);
    }
}

int dequeue(int q[],int *front,int *rear){
    int a;
    if(*front>*rear){
       *front=-1;
       *rear=-1;
       a=-1;
    }else{
        a=q[(*front)++];
    }
    return a;
}

int pop(int q1[],int q2[],int *f1,int *f2,int *r1,int *r2){
    int a,b=-1;
    if(*f1==-1 && *r1==-1){
    }else{
       while(*f1<*r1){
        a=dequeue(q1,f1,r1);
          enqueue(q2,f2,r2,a);
       }
       b=dequeue(q1,f1,r1);
       *f1=-1;
       *r1=-1;
       while(*f2!=-1 && *r2!=-1){
        a=dequeue(q2,f2,r2);
        if(a!=-1)
          enqueue(q1,f1,r1,a);
       }
    }
    return b;
}
void display(int q[],int front,int rear){
    for(int i=rear;i>=front;i--){
        printf("%d ",q[i]);
    }
    printf("\n");
}
int main(){
    int n,f1=-1,f2=-1,r1=-1,r2=-1,a;
    printf("enter the size:");
    scanf("%d",&n);
    int q1[n],q2[n];
    push(q1,&f1,&r1,10,n);
    push(q1,&f1,&r1,20,n);
    push(q1,&f1,&r1,30,n);
    push(q1,&f1,&r1,40,n);
    push(q1,&f1,&r1,50,n);
    display(q1,f1,r1);
    a=pop(q1,q2,&f1,&f2,&r1,&r2);
    printf("deleted value:%d\n",a);
    a=pop(q1,q2,&f1,&f2,&r1,&r2);
    printf("deleted value:%d\n",a);
    a=pop(q1,q2,&f1,&f2,&r1,&r2);
    printf("deleted value:%d\n",a);
    display(q1,f1,r1);
    return 0;
}