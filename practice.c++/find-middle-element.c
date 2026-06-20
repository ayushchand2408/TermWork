#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node * createNode(int value){
    node *temp = (node*)malloc(sizeof(node));
    temp -> info = value;
    temp -> next = NULL;
    return temp;
}

void insert(node **head , int value){
    node *temp  = createNode(value);
    temp -> next = *head;
    *head = temp;
}

void display(node *head)
{
    while(head != NULL)
    {
        printf("%d ",head -> info);
        head = head -> next;
    }
    printf("\n");
}

// int middle(node *head)
// {
//     if(head ==NULL){
//     printf("link list is empty");
//     return -1;
//     }
//     node *slow = head;
//     node *fast = head;
//     while(fast->next!= NULL && fast->next->next != NULL)
//     {
//         slow  = slow -> next;
//         fast = fast->next->next;
//     }
//     return slow->info;
// }
// void mergetwolinklist(node *head , node *head1)
// {
//     while(head != NULL || head1 != NULL){
//         if(head->info >= head1->info){
//             node *temp1 =head1; 
//             temp1 -> next = head;
//             head1=head1->next;
//             free(temp1);
//         }else if(head->info < head1->info)
//         {
//             node *temp1 =head1; 
//             temp1->next = head->next;
//             head->next = temp1;
//             head = head -> next;
//             free(temp1);
//         }
        
//     }   
// }
void mergetwolinklist(node** head1, node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    if (head2 == NULL) {
        return;
    }

    node* curr1 = *head1;
    node* prev1 = NULL;
    node* curr2 = head2;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->info > curr2->info) {
            if (prev1 == NULL) {
                *head1 = curr2;
            } else {
                prev1->next = curr2;
            }
            prev1 = curr2;
            curr2 = curr2->next;
            prev1->next = curr1;
        } else {
            prev1 = curr1;
            curr1 = curr1->next;
        }
    }
    
    if (curr2 != NULL) {
        prev1->next = curr2;
    }
}
void merge_sort(node **head1,node *head2)
{
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    if (head2 == NULL) {
        return;
    }
    node *curr1 = *head1;
    node * prev = NULL;
    node *curr2  = head2;

    while(curr1 != NULL && curr2 != NULL )
    {
        if(curr1->info >= curr2->info)
        {
            if(prev == NULL)
            {
                *head1 = curr2;
            }
            else{
                prev -> next = curr2;
            }
            prev = curr2;
            curr2 = curr2 -> next;
            prev -> next = curr1;
        }else{
            prev = curr1;
            curr1=curr1->next;
        }
    }
    if(curr2 != NULL){
        prev -> next = curr2;
    }
}

int main()
{
    node *head = NULL;
    node *head1 = NULL;

    insert(&head,19);
    insert(&head,18);
    insert(&head,17);
    insert(&head,16);
    insert(&head,15);

    insert(&head1,19);
    insert(&head1,14);
    insert(&head1,13);
    insert(&head1,12);

    merge_sort(&head1,head);

    display(head1);

}