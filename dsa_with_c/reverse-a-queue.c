#include <stdio.h>
#include <string.h>

void push(int st[],int  *top ,int val)
{
    st[++(*top)]=val;
}

void enqueue(int queue[],int *front , int *rear , int val,int n)
{
    if(*rear == n - 1)
    {
        printf("queue is full");
    }
    else{
        (*rear)++;
        if(*front == -1)
        {
          *front =  0;
        }
        queue[(*rear)] = val;
    }
}

void display(int st[] , int top)
{
    while(top != -1)
    {
        printf("%d ",st[top]);
        top--;
    }
}

void display1 ( int queue[] , int front , int rear)
{
    while(front <= rear)
    {
        printf("%d ",queue[front]);
        front++;
    }
}

int main()
{
    int n;
    printf("enter the size of queue\n");
    scanf("%d",&n);
    int queue[n],st[n],key,val,front=-1,rear = -1,top=-1;
    printf("1 to insert\n");
    printf("2 to exist\n");
    while(key != 2)
    {
        scanf("%d",&key);   
        switch(key){
            case 1:
            scanf("%d",&val);
            enqueue(queue,&front,&rear,val,n );
            push(st,&top,val);
            break;
            
            case 2:
            printf("reverse queue :- ");
            display(st , top);
            printf("insert queue :- ");
            display1(queue , front ,rear);
            break;
        }
    }
    
}