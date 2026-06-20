#include<stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *next;
};

typedef struct node node;
void enqueue(node **head,node **last,int v)
{
  node *temp;
  temp=(node*)malloc(sizeof(node));
  temp->info=v;
  temp->next=NULL;

  if(*head==NULL)
  {
      *head = temp;
      *last = temp;
  }
  else{
      (*last)->next = temp;
      *last=temp;
  }
    
}
node *dequeue(node*head)
{
  if(head == NULL)
  {
    printf( "stack is empty");
    return NULL;
  }
  else{
    node *temp=head;
    head = head->next;
    temp-> next = NULL;
    printf("element popped :- %d ",temp->info);
    printf("\n");
    return head;
  }
}
void display(node *head)
{
  while(head!=NULL)
  {
    printf("%d ",head->info);
    head=head->next;
  }
  printf("\n");
}
int main()
{
  node *head=NULL;
  node*last=NULL;
  enqueue(&head,&last,10);
  enqueue(&head,&last,20);
  enqueue(&head,&last,30);
  enqueue(&head,&last,40);
    enqueue(&head,&last,50);
    display(head);
    head=dequeue(head);
    head=dequeue(head);
    display(head);

  }
  
