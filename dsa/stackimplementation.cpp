#include<bits/stdc++.h>
using namespace std;
void push(int arr[], int *top , int n , int num ) {

    if((*top) >= n-1)
    {
        cout<<"stack is full";
    }

    else
    {
    
        arr[++(*top)]=num;
    }
    
}

void pop(int arr[],int *top)
{
     if(*top==-1)
     {
        cout << "stack is empty";
     }
     else{
        cout << "deleted value "<< arr[*top];
        (*top)--;
     }

    cout<<endl;
}
int main()
{
    int n , top = -1;
    cin>>n;
   int arr[n];


    for(int i = 0 ; i < n ; i++)
    {
        int num;
        cin>>num;
        push(arr , &top , n , num);
    }
    pop(arr,&top);
}