#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = *max_element(arr, arr + n);
    int freq[max + 1];
    memset(freq,0,sizeof(freq));

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

    cout << "Sorted array: ";  
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
