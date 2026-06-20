#include<iostream>
using namespace std;

void heapify(int arr[],int i,int n){
    int parent = i;
    int left = 2 * i;
    int right = 2*i+1;
    if(left <= n && arr[left] > arr[parent]){
        parent=left;
    }
    if(right <= n && arr[right] > arr[parent]){
        parent = right;
    }
    if(parent != i){
        swap(arr[parent],arr[i]);
        heapify(arr,parent,n);
    }
}
void heapsort(int arr[],int n){
    for(int i = n/2 ; i >1; i--){
        heapify(arr,i,n);
    }
    for(int i = n ; i > 1 ; i--){
        swap(arr[1],arr[i]);
        heapify(arr,1,i-1);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 1 ; i  <= n ; i++){
        cin >> arr[i];
    }
    heapsort(arr,n);
    cout  <<"sorted array : ";
    for(int i = 1 ; i  <= n ;  i++){
        cout << arr[i] << " ";
    }
}