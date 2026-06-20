#include<iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right, int &comparisons) {
    int i = left;  
    int j = mid + 1; 
    int k = left; 
    int inversions = 0;
    int temp[right+1];

    while((i <= mid) && (j <= right)) {
        comparisons++;
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid-i+1);
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

    return inversions;
}

int mergeSort(int arr[] ,int left, int right, int &comparisons) {
    int mid, inversions = 0;
    if(right > left) {
        mid = (right + left) / 2;

        inversions += mergeSort(arr, left, mid, comparisons);
        inversions += mergeSort(arr, mid+1, right, comparisons);
        inversions += merge(arr, left, mid, right, comparisons);
    }
    return inversions;
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
    
    int comparisons = 0;
    int inversions = mergeSort(arr ,0, n-1, comparisons);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of inversions: " << inversions << endl;
    
    return 0;
}
