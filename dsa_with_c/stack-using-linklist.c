#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};

typedef struct node node;

node* push( node *top,int v)
{
    node*temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = v;
    temp->next=top;
    top=temp;
    return top;

}
node*pop(node*top)
{
    if(top==NULL)
    {
        printf("stack is empty");
        return NULL;
    }
    else{
        node* temp=top;
        top= top->next;
        temp->next=NULL;
        printf("element popped :- %d ",temp->info);
        printf("\n");
        return top;

    }
}
void display(node* top)
{
    while(top != NULL)
    {
        printf("%d ",top->info);
        top=top->next;
    }
    printf("\n");
}

int main()
{
    node *top = NULL;
    top = push(top,5);
    top = push(top,8);
    top = push(top,12);
    top = push(top,19);
    display(top);
    top = pop(top);
    top = pop(top);
    display(top);


}