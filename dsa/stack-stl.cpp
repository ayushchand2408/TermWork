#include<iostream>
#include <queue>
using namespace std;
queue <int>q1;
queue <int> q2;
void push(int val){
     q2.push(val);
     while(!q1.empty()){
        int a=q1.front();
        q1.pop();
        q2.push(a);
     }  
     swap(q1,q2);  
}
int pop(){
    int a=-1;
    if(q1.empty()){
        cout<<"stack is empty"<<endl;
    }else{
      a=q1.front();
      q1.pop();
    }
    return a;
}
int main(){
    int a;
   push(20);
   push(40);
   push(60);
   a=pop();
   cout<<"deleted number="<<a<<endl;
   a=pop();
   cout<<"deleted number="<<a<<endl;
}