#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node* createNode(int x)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->info = x;
    temp->next = NULL;
    return temp;
}

void insert(node**head,int v)
{
    node* temp = createNode(v);
    if (*head == NULL) {
        *head = temp;
    } else {
        temp->next = *head;
        *head = temp;
    }
}

void insertAtlast(node **head,int v)
{
    node* temp = createNode(v);
    node *temp2=*head;
    if(*head==NULL)
    {
        *head = temp;
    }
    else{
        while(temp2->next !=NULL){
            temp2=temp2->next;
        }
        temp2->next = temp;
    }
}

void insertATbw(node**head,int ind,int v)
{
    node* temp = createNode(v);
    node *temp2=*head;
    if(*head == NULL)
    {
        *head = temp;
    }
    else{
        while(temp2->info != ind){
            temp2=temp2->next;
        }
        temp->next = temp2->next;
        temp2->next=temp;
    }
}

void delete(node **head ,int v)
{
    node *temp = *head;
    while(temp->next->info != v)
    {
        temp=temp->next;
    }
    temp->next = temp->next->next;

}

void reverse(node**head)
{
    node *current = *head;
    node *prev=NULL;
    while(current !=NULL){
        node *n = current->next;
        current -> next=prev;
        prev = current;
        current = n;
    }
    *head = prev;
}

void display(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    node *head=NULL;

    insert(&head,10);
    insert(&head,20);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    insertAtlast(&head,30);
    insertATbw(&head,50,55);
    delete(&head,30);
   
     
    display(head);

    reverse(&head);
    display(head);
}