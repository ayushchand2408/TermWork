#include<iostream>
using namespace std;

int binary_Search(int arr[], int low, int high, int k, int& comparisons) {
    int count = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if (arr[mid] == k) {

            int first = mid, last = mid;
            while (first > low && arr[first - 1] == k) {
                comparisons++;
                first--;
            }
            while (last < high && arr[last + 1] == k) {
                comparisons++;
                last++;
            }
            return last - first + 1;
        }
        if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, key, comparisons = 0;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array (sorted in ascending order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key element to search for: ";
    cin >> key;

    int count = binary_Search(arr, 0, n-1, key, comparisons);
    if (count != -1) {
        cout << "Present : " << endl;
    } else {
        cout << "Not Present" << endl;
    }
    cout << "Total number of comparisons: " << comparisons << endl;

    return 0;
}
