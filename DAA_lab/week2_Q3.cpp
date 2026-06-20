#include<iostream>
using namespace std;

int main(){
    int n, K;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the value of K: ";
    cin >> K;
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(abs(arr[i] - arr[j]) == K) {
                count++;
            }
        }
    }
    
    cout << "Number of pairs with difference " << K << " is: " << count << endl;
    
    return 0;
}
