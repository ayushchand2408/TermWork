  
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
int isSumPossible(vector<int>& arr, int sum, vector<vector<int>>& mat ,int index, int 
currSum) { 
    if(currSum == sum) return 1; 
    if(currSum > sum) return 0; 
    if(index>=arr.size()) return 0; 
    if(arr[index] > sum) mat[index][currSum] = isSumPossible(arr,sum,mat,index+1,currSum); 
    if(mat[index][currSum]!=-1) return mat[index][currSum]; 
 
    return mat[index][currSum] = isSumPossible(arr,sum,mat,index+1,currSum) || isSumPossible(arr,sum,mat,index+1,currSum+arr[index]); 
} 
 
int main() { 
    vector<int> arr; 
    int n, sum=0; 
    cout<<"Enter the number of elements:"; 
    cin>>n; 
    cout<<"Enter the elements:"; 
    for(int i=0; i<n; i++) { 
        int num; 
        cin>>num; 
        arr.push_back(num); 
        sum+=num; 
    } 
    if(sum%2==0) { 
        vector<vector<int>> mat(n,vector<int>(sum/2+1,-1)); 
        if(isSumPossible(arr,sum/2,mat,0,0)) cout<<"True"; 
        else cout<<"False"; 
    }else { 
        cout<<"False"; 
    } 
} 