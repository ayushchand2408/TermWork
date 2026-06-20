#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int comparisons = 0;
    int shifts = 0;
    
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
            shifts++;
        }
        arr[j + 1] = key;
        shifts++;
    }
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "comparisons: " << comparisons << endl;
    cout << "shifts: " << shifts << endl;
    
    return 0;
}
