#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node *Create(int val)
{
    node * temp = (node*)malloc(sizeof(node));
    temp -> info = val;
    temp->next = NULL;
    return temp;
}

void insertAtFront(node **head , int val)
{
    node * temp = Create(val); 
    temp->next = *head;
    *head = temp;
}
void positive_no(node **head)
{
    node *temp= *head;
    int count =0;
    while(temp ->next != NULL)
    {
        if((temp -> info) > 0)
        {
            count ++;
        }
        temp = temp->next;
    }
    printf("+ve no : %d",count);
}
int main()
{
    node * head = NULL;
    printf("Press:\n1 insert node at front\n2 insert node at last\n3 insert node at specific position\n4 delete node from front\n5 delete node from last\n6 delete node from specific position\n7 find size of linked list \n8 find middle element of the list\n9 exit\n");
    int choice,val,i;
    while(choice!=2){
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("enter value : ");
        scanf("%d",&val);
        insertAtFront(&head,val);
        break;
        case 3:
        positive_no(&head);
        break;

        default:
        break;

    }  
    }
    
}
