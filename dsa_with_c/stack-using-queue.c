#include <stdio.h>

void push(int queue1[],  int *front1, int *rear1, int queue2[], int *front2, int *rear2, int size, int value)
{
    if(*rear1==size-1)
	{
        printf("Stack is full...\n");
        return;
    }
    else if(*rear2==-1)
	{
        *front2=0;
		*rear2=0;
    }
	else
	{
        (*rear2)++;
    }
    queue2[*rear2] = value;
    while(*front1!=-1)
	{
        queue2[++(*rear2)]=queue1[(*front1)++];
        if(*front1>*rear1)
		{
            *front1=*rear1=-1;
        }
    }
    for(int i=*front2;i<=*rear2;i++)
	{
        queue1[i-*front2]=queue2[i];
    }
    *front1=0;
    *rear1=*rear2-*front2;
    *front2=-1;
	*rear2=-1;
}

int pop(int queue1[], int *front1, int *rear1)
{
    int v;
    if(*front1 == -1)
	{
        printf("Stack is empty...\n");
        return -1;
    }

    printf("%d has been removed...\n", queue1[*front1]);
    if(*front1==*rear1)
	{
        *front1=*rear1=-1;
    }
	else
	{
        v = (*front1)++;
    }
    return v;
}

void display(int queue1[], int front1, int rear1) {
    if(front1==-1)
	{
        printf("Stack is empty...\n");
        return;
    }

    for(int i=front1;i<=rear1;i++)
	{
        printf("%d ", queue1[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &size);

    int queue1[size], queue2[size];
    int front1=-1, rear1=-1, front2=-1, rear2=-1,key,value;

    printf("1 to insert\n2 to pop\n3 to exit\n");

    while(key != 3)
    {
        scanf("%d",&key);
        switch(key){
            case 1:
            scanf("%d",&value);
            push(queue1,&front1,&rear1,queue2,&front2,&rear2,size,value);
            printf("stack :- ");
            display(queue1,front1,rear1);
            break;
      
            case 2:
            pop(queue1,&front1,&rear1);
            break;

            case 3:
            printf("Stack after operation");
            display(queue1,front1,rear1);

        }
    }

    return 0;
}