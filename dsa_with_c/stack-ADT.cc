#include<iostream> 
#include<climits> 

using namespace std; 

typedef struct stack{ 
    int top; 
    int capacity; 
    int *array; 
}stack; 

stack* create_stack(int cap){ 
    stack *st=(stack*)malloc(sizeof(stack)); 
    st->capacity=cap; 
    st->top=-1; 
    st->array=(int*)malloc(sizeof(int)*st->capacity); 
    return st; 
} 

void push(stack *st,int value){ 
    if(st->top>=st->capacity-1){ 
        cout<<"stack is full."<<endl; 
        return; 
    } 
    st->array[++(st->top)]=value; 
} 

int pop(stack *st){ 
    if(st->top==-1){ 
        cout<<"stack is empty"<<endl; 
        return INT_MIN; 
    } 
    return st->array[(st->top)--]; 
}  

void display(stack *st)
{
    int s = st->top;
    while(s!= -1)
    {
        cout << st->array[s] << " " ;
        s -=1;
    }
    cout << endl;
}

int main(){ 
    stack *st=create_stack(10); 
    push(st,12); 
    push(st,18);
    push(st,24); 
    push(st,29); 

    display(st);

    cout<<"Popped element: "<<pop(st)<<endl; 
    cout<<"Popped element: "<<pop(st)<<endl; 
    return 0; 
} 