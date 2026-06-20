//INSERTION OF ELEMENT IN-BETWEEN TWO NODES 
#include <iostream> 
using namespace std; 
struct node{ 
    int info; 
    struct node* next; 
}; 
typedef struct node node; 

void display(node *head){ 
    while(head!=NULL){ 
        cout<<head->info<<" "; 
        head=head->next; 
    } 
    cout<<endl; 
} 
 

node * insert(node **head,int val){ 
   node *temp=(node*)malloc(sizeof(node)); 
   temp->info=val; 
   if(*head==NULL){ 
       temp->next=NULL; 
       *head=temp; 
   }else{ 
       temp->next=*head; 
       *head=temp; 
   } 
} 
 

void insertbt(node *head,int val, int prev_val){ 
    while(head!=NULL){ 
        if(head->info==prev_val){ 
            node *temp=(node*)malloc(sizeof(node)); 
            temp->info=val; 
            temp->next=head->next; 
            head->next=temp; 
            break; 
        } 
        head=head->next; 
    } 
} 
int main(){ 
    node* head=NULL; 
    int val,prev_val; 
    insert(&head,10); 
    insert(&head,20); 
    insert(&head,30); 
    insert(&head,40); 
    cout<<"elements in Linklist : "; 
    display(head); 
    cout<<"Enter the element to insert:"; 
    cin>>val; 
    cout<<"Enter after which element you want to insert:"; 
    cin>>prev_val; 
    insertbt(head,val,prev_val); 
    cout<<"elements after inserting in-between:"; 
    display(head); 
    return 0; 
}