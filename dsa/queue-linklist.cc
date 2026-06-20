#include<iostream>

using namespace std;

struct node{
    int info;
    struct node *next;
};
void insert(node **head,node **last,int v)//enqueue
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
  node *pop(node*head)//dequeue
  {
    if(head == NULL)
    {
      cout << endl << "stack is empty";
      return NULL;
    }
    else{
      node *temp=head;
      head = head->next;
      temp-> next = NULL;
      cout << endl << "element popped" << "-" << temp -> info << endl;
      return head;
    }
    
  }
  void display(node *head)
  {
    while(head!=NULL)
    {
        cout << head -> info << " ";
        head=head->next;
    }
    cout << endl;
  }

typedef struct node node;
int main()
{
    node *head=NULL;
    node *last=NULL;
    insert(&head,&last,10);//enqueue
    insert(&head,&last,20);
    insert(&head,&last,30);
    insert(&head,&last,40);
    insert(&head,&last,50);
    display(head);
    head=pop(head);//dequeue
    head=pop(head);
    display(head);
}