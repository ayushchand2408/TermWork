#include<iostream>
using namespace std;

int binary_search(int arr[],int low,int high,int k){
    int count = 0;
    while(low<=high){
        count++;
        int mid = (high + low)/2;
        if(arr[mid] == k){
            return count;
        }
        if(arr[mid] < k){
            low = mid+1;
        }
        if(arr[mid] > k){
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter the size of array : ";
    cin >> n;
    int arr[n];
    for(int i = 0 ;i < n ; i++){
        cin >> arr[i];
    }
    int k;
    cout<<"enter th element you want to search : ";
    cin >> k;
    int count = binary_search(arr,0,n-1,k);
    if(count == -1){
        cout<<"not present" << "\n";
    }else{
        cout << "present : " << count << "\n";
    }
}