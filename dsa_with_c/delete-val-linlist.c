#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};

typedef struct node node;

node* insert( node *head,int v)
{
    node*temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = v;
    temp->next=head;
    head=temp;
    return head;

}

void delete(node **head, int v) {
    node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->info == v) {
        *head = temp->next; 
        free(temp); 
        temp = *head; 
    }
    while (temp != NULL) {
        while (temp != NULL && temp->info != v) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) 
        return;
        prev->next = temp->next;

        free(temp); 
        temp = prev->next;
    }
}


void display(node* head)
{
    while(head != NULL)
    {
        printf("%d ",head->info);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    head = insert(head,5);
    head = insert(head,8);
    head = insert(head,12);
    head = insert(head,19);
    display(head);
    delete(&head , 19);
    display(head);


}