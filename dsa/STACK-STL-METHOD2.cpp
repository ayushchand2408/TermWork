#include<iostream>
#include <queue>
using namespace std;
queue <int>q1;
queue <int> q2;
void push(int val,int *size){
    q1.push(val);
    (*size)++;
}
int pop(int *size){
    int i=1;
    while(i<*size){
       int a=q1.front();
       q1.pop();
       q2.push(a);
       i++;
    }
    int b=q1.front();
    q1.pop();
    (*size)--;
    swap(q1,q2);
    return b;
}
int main(){
    int size=0;
    push(1,&size);
    push(2,&size);
    push(3,&size);
    push(4,&size);
    cout<<"deleted value="<<pop(&size)<<endl;
    cout<<"deleted value="<<pop(&size)<<endl;
    cout<<"deleted value="<<pop(&size)<<endl;
}