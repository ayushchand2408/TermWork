#include<iostream> 
#include<climits> 

using namespace std; 

typedef struct node{ 
    int info; 
    struct node * next; 
}node; 

typedef struct stack{ 
    struct node *top; 
}stack; 

void initializeStack(stack *st){ 
    st->top=NULL; 
} 

node * create_node(int value){ 
    node* temp=(node*)malloc(sizeof(node)); 
    temp->info=value; 
    temp->next=NULL; 
    return temp; 
} 

void push(stack *st,int value){ 
    node* temp=create_node(value); 
    if(!temp){ 
        cout<<"not sufficient memory"<<endl; 
    } 
    else{ 
        temp->next=st->top; 
        st->top=temp; 
    } 
} 

int pop(stack *st){ 
    node* temp=st->top; 
    if(st->top==NULL){ 
        cout<<"stack is empty"<<endl; 
        return INT_MIN; 
    } 
    else{ 
        st->top=st->top->next; 
        temp->next=NULL; 
        int value=temp->info; 
        delete temp; 
        return value; 
    } 
} 

void display(stack *st)
{
    node* temp=st->top; 
    while(temp != NULL)
    {
        cout << temp -> info<< " " ;
        temp= temp->next;
    }
    cout << endl;
}

int main(){ 
    stack *st=new stack; 
    initializeStack(st); 
    push(st,1); 
    push(st,3); 
    push(st,5); 
    push(st,7); 
    push(st,9); 

    display(st);

    cout<<"Popped element: "<<pop(st)<<endl; 
    cout<<"Popped element: "<<pop(st)<<endl; 
    cout<<"Popped element: "<<pop(st)<<endl; 
    return 0; 
} 
