#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    bool found = false;
    
    for(int k = 0; k < n && !found; k++) {
        for(int i = 0; i < n - 1 && !found; i++) {
            for(int j = i + 1; j < n && !found; j++) {
                if(arr[i] + arr[j] == arr[k]) {
                    cout << i << ", " << j << ", " << k << endl;
                    found = true;
                }
            }
        }
    }
    
    if(!found) {
        cout << "No sequence found" << endl;
    }
    
    return 0;
}
