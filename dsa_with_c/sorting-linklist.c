#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node * next;
};

typedef struct node node;

 void insert(node **head,int v)
  {
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=v;
    temp-> next =NULL;
    node *temp2 ;
    temp2 = *head;


    if(*head==NULL)
    {
        *head = temp;
    }
    else if((*head)->next == NULL){
        if((*head)->info > temp->info)
        {
            temp->next = *head;
            *head = temp;
        }
        else{
            (*head)-> next = temp;
        }
    }
    else if((*head)->info > v){
        temp->next = *head;
        *head = temp;
    }
    else{
        while(temp2 -> next != NULL && temp2->next->info < v)
        {
            temp2=temp2->next;
            
        }
        temp-> next=temp2->next;
        temp2-> next = temp;
        
    }
  }
 

  void display(node* head)
  {
    while(head != NULL)
    {
        printf("%d ",head->info);
        head = head -> next;
    }
    printf("\n");
  }

int main()
{
    node *head = NULL;
    insert(&head,70);
    insert(&head,10);
    insert(&head,6);
    insert(&head,9);
    display(head);
}