#include<iostream>

using namespace std;

struct node{
    int info;
    struct node *next;
};
  node *insert(node *head,int v)
  {
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=v;
    temp->next=head;
    head=temp;
    return head;

    // if(head==NULL)
    // {
    //     head=(node*)malloc(sizeof(node));
    //     head -> info=v;
    //     head -> next=NULL;
    // }
    // else{
    //     node *temp;
    //     temp=(node*)malloc(sizeof(node));
    //     temp->info=v;
    //     temp->next=head;
    //     head=temp;
    // }
    // return head;
  }
  node *pop(node*head)
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
      cout << endl << "element popped" << "-" << temp -> info ;
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
    head=insert(head,10);
    // head=insert(head,20);
    // head=insert(head,30);
    // head=insert(head,40);
    // head=insert(head,50);
    display(head);
    head=pop(head);
    head=pop(head);
    display(head);
}