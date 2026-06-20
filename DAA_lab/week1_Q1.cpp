#include<iostream>
#include<map>
using namespace std;

int search(int arr[] , int n,int k){
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        count++;
        if(arr[i]==k){
            return count;
        }
    }
    return count;
}

int main(){
    int n;
    cout<<"enter the size of array ";
    cin >> n;
    int arr[n];
    cout<<"enter the element of array : ";
    for(int i = 0 ;i < n ; i++){
        cin >> arr[i];
    }
    int k;
    cout<< "enter the value of element you want to search : ";
    cin >> k;
    int count = search(arr,n,k);
    if(count == n){
        cout<<"not present" << count <<"\n";
    }else{
        cout<<"present : "<<count << "\n";
    }
    

}