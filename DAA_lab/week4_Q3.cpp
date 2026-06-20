#include<iostream>
#include<algorithm>
using namespace std;

int smallest(int arr[],int n){
    int min = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int k_smallest_number(int arr[] , int k ,int n ,int min){
    int max = *max_element(arr, arr + n);
    int freq[max + 1] = {0};

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for(int i = 1; i <= max; i++) {
        freq[i] += freq[i - 1];
    }
 
    int b[n];
    for(int i = n - 1; i >= 0; i--) {
        int ind = --freq[arr[i]];
        b[ind] = arr[i];
    }
    for(int i = 0 ; i<n ; i++){
        b[i] = b[i] - min;
    }

    return b[k-1];
}

int main(){
    int n,min;
    cout<<"enter the size of array :- ";
    cin >>n;
    bool check;
    int arr[n];
    for(int j = 0  ; j < n ; j++){
        cin >> arr[j];
    }
    int k;
    cout << "enter the value of k :-";
    cin >> k;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < 0){
            check = false;
        }
    }
    if(!check){
        min = -smallest(arr,n);
    }
    for(int i = 0 ;i < n ; i++){
        arr[i]=arr[i]+min;
    }
    int element = k_smallest_number(arr,k,n,min);
    cout<<"smallest element :- " << element ;
    
}