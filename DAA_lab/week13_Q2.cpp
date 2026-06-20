#include <iostream> 
#include <vector> 
#include <unordered_set> 
using namespace std; 
 
void isDuplicateInKthWindow(vector<int>& nums, int n, int k) { 
    unordered_set<int> set; 
 
    for(int i=0; i<n; i++) { 
        if(set.find(nums[i])!=set.end()) { 
            cout<<"Duplicate element found at window size "<<k<<endl; 
            return; 
        }  
        else { 
            set.insert(nums[i]); 
        } 
 
        if(i>=k) { 
            set.erase(nums[i-k]); 
        } 
    } 
    cout<<"Duplicate element not found at window size "<<k<<endl; 
} 
 
int main() { 
    int n, k; 
    cout<<"Enter the number of elements:"; 
    cin>>n; 
    vector<int> nums(n); 
    cout<<"Enter the elements of the array:"; 
    for(int i=0; i<n; i++) cin>>nums[i]; 
    cout<<"Enter the window size:"; 
    cin>>k; 
    isDuplicateInKthWindow(nums,n,k); 
    return 0; 
} 