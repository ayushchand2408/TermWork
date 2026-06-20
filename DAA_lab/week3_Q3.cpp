#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right) {
    int i = left;  
    int j = mid + 1; 
    int k = left; 
    int temp[right+1];

    while((i <= mid) && (j <= right)) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

}

int mergeSort(int arr[] ,int left, int right) {
    int mid, inversions = 0;
    if(right > left) {
        mid = (right + left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
    return inversions;
}

bool hasDuplicates(int arr[], int n) {
    mergeSort(arr,0,n-1);
    
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] == arr[i + 1]) {
            return true; 
        }
    }
    
    return false; 
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if(hasDuplicates(arr, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
