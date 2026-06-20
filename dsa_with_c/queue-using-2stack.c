#include <stdio.h>
#include <stdbool.h>

void push(int st[],int val,int *top){
    st[++(*top)]=val;
}
int pop(int st[],int *top){
    if(*top==-1){
        printf("queue is empty\n");
        return -1;
    }
    int a=st[(*top)--];
    return a;

}
void enqueue(int s1[],int s2[],int *top1,int *top2,int val,int n){
    int a;
    while(*top1!=-1){
        a=pop(s1,top1);
        push(s2,a,top2);
    }
    push(s1,val,top1);
    while(*top2!=-1){
        a=pop(s2,top2);
        push(s1,a,top1);
    }
}
void display(int st[],int top){
    for(int i=top;i>=0;i--)
        printf("%d ",st[i]);
    printf("\n");
}
int dequeue(int s1[],int *top){
    int a=pop(s1,top);
    return a;
}

int main(){
    int top1=-1,top2=-1,n,a,key,v;
    printf("enter the size of array");
    scanf("%d",&n);
    int s1[n],s2[n];
    printf("1 to insert\n2 to pop\n3 to exit\n");
    while(key!=3)
    {
        scanf("%d",&key);
        switch(key){
            case 1:
            scanf("%d",&v);
            enqueue(s1,s2,&top1,&top2,v,n);
            display(s1,top1);
            break;

            case 2:
            printf("element delted from queue %d\n",dequeue(s1,&top1));
            break;

            case 3:
            printf("Queue after deletion : ");
            display(s1,top1);

        }
    }
    return 0;
}
