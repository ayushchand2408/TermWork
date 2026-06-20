#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node * createnode(int value){
    node * temp = (node*)malloc(sizeof(node));
    temp->info = value;
    temp -> next = NULL;

    return temp;
}
void insert(node **head,int value){
    node *temp = createnode(value);
    if(*head == NULL)
    {
        *head = temp; 
    }else{
    temp->next = *head;
    *head = temp;
    }
}

node * reverse(node *head)
{
    if(head == NULL|| head->next ==NULL)
    {
        return head;
    }
    node*prev=reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return prev;

}

void display(node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->info);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node * head = NULL;
    insert(&head,12);
    insert(&head,13);
    insert(&head,15);
    insert(&head,16);
    insert(&head,17);

    display(head);

    head =reverse(head);

    display(head);

}