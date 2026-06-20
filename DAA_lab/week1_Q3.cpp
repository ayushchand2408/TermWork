#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key, int &comparisons) {
    int step = sqrt(n);  
    int prev = 0;
    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; 
        }
    }

    while (arr[prev] < key) {
        comparisons++;
        prev++;
        if (prev == min(step, n)) {
            return -1;  
        }
    }
    comparisons++;
   
    if (arr[prev] == key) {
        return prev;
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

    int result = jumpSearch(arr, n, key, comparisons);
    if (result != -1) {
        cout << "Present : " << comparisons << endl;
    } else {
        cout << "Not Present " << comparisons << endl;
    }
    cout << "Total number of comparisons: " << comparisons << endl;

    return 0;
}
