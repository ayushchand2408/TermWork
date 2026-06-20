#include<iostream> 
#include<climits> 
using namespace std; 
typedef struct queue{ 
    int front; 
    int rear; 
    int capacity; 
    int * array; 
}queue; 

queue* create_queue(int cap){ 
    queue* q=(queue*)malloc(sizeof(queue)); 
    q->capacity=cap; 
    q->front=-1; 
    q->rear=-1; 
    q->array=(int*)malloc(sizeof(int)*q->capacity); 
    return q; 
} 

void enqueue(queue *q,int value){ 
    if(q->rear>=q->capacity-1){ 
        cout<<"queue is full"<<endl; 
        return; 
    } 
    q->array[++(q->rear)]=value; 
    if(q->front==-1){ 
        q->front=0; 
    } 
} 

int dequeue(queue *q){ 
    if(q->front>q->rear){ 
        cout<<"queue is empty"<<endl; 
        return INT_MIN; 
    } 
    else{ 
        int value=q->array[(q->front)++]; 
        if(q->front>q->rear){ 
            q->front=-1; 
            q->rear=-1; 
        } 
        return value; 
    } 
} 

void display(queue *q)
{
    int s = q -> front;
    while(s <= q->rear)
    {
        cout << q->array[s] << " " ;
        s +=1;
    }
    cout << endl;
} 

int main(){ 
    queue *q=create_queue(10); 
    enqueue(q,10); 
    enqueue(q,20); 
    enqueue(q,25); 
    enqueue(q,35); 
    enqueue(q,45);

    display(q); 

    cout<<"dequeued element: "<<dequeue(q)<<endl; 
    cout<<"dequeued element: "<<dequeue(q)<<endl; 
    return 0; 
} 
