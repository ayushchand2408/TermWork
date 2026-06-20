#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int *array;
}stack;

stack * createNode(int cap)
{
    stack *st = (stack*)malloc(sizeof(stack));
    st -> top = -1;
    st -> capacity  = cap ;
    st -> array = (int*)malloc(sizeof(int));
    return st;
}

void push(stack * st , int v)
{
    if(st -> top >= st->capacity)
    {
        printf("stack is full\n");
        return;
    }
    st->array[++(st->top)]= v;
}

int pop(stack * st)
{
    if(st -> top == -1)
    {
        printf("stack is empty\n");
        return 0;
    }
    return  st->array[(st->top)--];
}

void display(stack *st)
{
    int s = st->top;
    while(s !=-1)
    {
        printf("%d " , st->array[(s)]);
        s--;
    }
    printf("\n");
}

int main()
{
    stack *st = createNode(10);

    push(st,10);
    push(st,19);
    push(st,12);
    push(st,18);
    push(st,13);
    push(st,29);

    display(st);

    printf("poped value  %d \n" , pop(st));
    printf("poped value  %d \n" , pop(st));


}
