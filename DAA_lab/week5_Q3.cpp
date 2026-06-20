#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ;
    cout<<"enter the size of first array : ";
    cin >> n;
    int arr1[n];
    cout << " enter the element of of first array ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr1[i];
    }
    int m ; 
    cout << "enter the size of second array : ";
    cin >> m;
    int arr2[m];
    cout<<"enter the element of second array : ";
    for(int i = 0 ; i < m ; i++){
        cin >> arr2[i];
    }
    vector<int>result;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr1[i] == arr2[j]){
                result.push_back(arr1[i]);
                arr2[j] = -1000;
                break;
            }
        }
    }
    for(int i = 0 ; i < result.size() ; i++){
        cout << result[i] << " ";
    }

}