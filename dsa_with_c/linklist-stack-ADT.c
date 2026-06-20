#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    struct node *top;
}stack;
typedef struct node{
    int info;
    struct node *next;
}node;
stack* intializeStack()
{
    stack *st =(stack*)malloc(sizeof(stack));
    st->top = NULL;
    return st;
}
node *CreateNode(int v)
{
    node * temp = (node*)malloc(sizeof(node));
    temp -> info = v;
    temp -> next = NULL;
    return temp;
}
void push(stack * st , int v)
{
    node *temp = CreateNode(v);
    if(!temp){
        printf("not sufficient memory");
    }
    else{
        temp -> next = st -> top;
        st->top= temp;
    }
}
int pop(stack *st)
{
    node *temp  = st->top;
    if(st -> top == NULL)
    {
        printf("stack is empty");
        return -1;
    }
    else{
        st->top = st->top->next;
        temp -> next = NULL;
        int val = temp -> info ;
        free(temp);
        return val;
        
    }
}
void display(stack *st)
{
    node *temp = st ->top ;
    while(temp != NULL)
    {
        printf("%d " , temp -> info);
        temp =temp -> next ;
    }
    printf("\n");
}
int size(stack *st)
{
    int count=0;
    node *temp = st->top;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    return count;
}
int main() {
    stack* st = intializeStack();
    int choice, data;
    printf("Press:\n1 to push\n2 to pop\n3 to calculate size\n4 to exit\n");
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            printf("Enter the value: ");
            scanf("%d", &data);
            push(st, data);
            display(st);
            break;

            case 2:
            printf("poped value: %d\n", pop(st));
            display(st);
            break;

            case 3:
            printf("Size of stack: %d\n", size(st));
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
