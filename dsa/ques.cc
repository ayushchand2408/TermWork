#include <iostream>
using namespace std;

void enqueue(int q[],int *front,int *rear,int v,int n){
    if(*rear==n-1)
    {
        cout <<"queue is full" << endl;
    }else{
        (*rear)++;
       
        if(*front == -1){
            *front = 0;
        }
         q[*rear] = v;
    }

}
    void display(int q[], int front , int rear)
    {
        if(front != -1)
        {
      for(int i = front ; i<=rear;i++)
      {
        cout << q[i] << " ";
      }
      cout << endl;
        }
        else{
            cout << "stack is empty" ;
        }
    }

    int dequeue(int q[], int *front , int *rear)
    {
        if(*front == -1)
        {
            cout << "queue is empty" << endl;
           
        }
        else
        {
            int k = q[(*front)];
            (*front)++ ;
            if(*front > *rear)
            {
                
            *front = *rear = -1;
            }
            return k;
        }
        
    }

int main()
{
     int n;

     cout <<"enter the size of queue";
     cin>> n;

     int q[n];
     int front =-1,rear=-1;
     enqueue(q,&front,&rear,12,n);
     enqueue(q,&front,&rear,13,n);
     enqueue(q,&front,&rear,14,n);
     enqueue(q,&front,&rear,15,n);
     enqueue(q,&front,&rear,16,n);
     display(q,front,rear);
     
     cout << "deleted value : " << dequeue(q,&front,&rear) << endl;
     cout << "deleted value : " << dequeue(q,&front,&rear) << endl;
     cout << "deleted value : " << dequeue(q,&front,&rear) << endl;
     cout << "deleted value : " << dequeue(q,&front,&rear) << endl;
     cout << "deleted value : " << dequeue(q,&front,&rear) << endl;

     display(q,front,rear);
}