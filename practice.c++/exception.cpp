#include<iostream>
#include<stdexcept>
#include<cmath>

using namespace std;

int main(){
    int n;
    cout<<"enter the number you want to find root of : ";
    cin >> n;
    
    try{
        float c = sqrt(n);
        if(c <= 0){
            throw 101;
        }
        cout<<"sqrt : " << c;
    }
    catch(int){
        cout<<"invalid input";
    }
}