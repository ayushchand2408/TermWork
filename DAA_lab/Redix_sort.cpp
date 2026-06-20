#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

// Function to perform counting sort on a specific digit (exp)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0}; // Count array for digits 0-9

    // Count occurrences of each digit at current place value 
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[i] to store the actual position of this digit
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array by placing elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copy sorted array back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to implement Radix Sort
void radixSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end()); 
    // Find the max number
    // Apply counting sort for each digit place (1s, 10s, 100s, ...)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Driver code
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}