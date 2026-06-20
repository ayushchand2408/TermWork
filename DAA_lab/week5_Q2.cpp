#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[],int low, int mid,int high){
    int temp[high+1];
    int i = low , k=low , j = mid +1;
    while(i <= mid && j <= high ){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[ i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    for(int i = low ; i <= high ; i++){
        arr[i] = temp[i];
    }
}

void mergesort(int arr[] ,int low ,  int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        mergesort(arr,low , mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);   
    }
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t > 0) {
        int n;
        cout << "Enter the size of array: ";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k;
        cout << "Enter the sum of the number you want to search: ";
        cin >> k;
        mergesort(arr,0,n-1);
        bool check = false;
        int low = 0, high = n - 1;

        while (low < high) {
            int sum = arr[low] + arr[high];
            if (sum == k) {
                cout << arr[low] << " " << arr[high] << endl;
                check = true;
                break;
            } else if (sum < k) {
                low++;
            } else {
                high--;
            }
        }

        if (!check) {
            cout << "No Such Elemnt Exist" << endl;
        }

        t--;
    }

    return 0;
}
