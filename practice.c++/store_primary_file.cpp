#include<iostream>
#include<fstream>

using namespace std;
bool isprime(int value) 
{ 
    if (value <= 1) return false; // 0 and 1 are not prime numbers 
    for (int i = 2; i * i <= value; i++) 
    { 
        if (value % i == 0) return false; 
    }
    return true;
}
int main(){
    int arr[5];
    cout<<"enter the element of array : ";
    for(int i = 0 ; i <5 ; i++){
        cin >> arr[i];
    }
    ofstream out("destination.txt");
    for(int i = 0  ; i < 5 ; i++){
        if(isprime(arr[i])== true){
            out << arr[i]<<" ";
        }
    }
    out.close();
}