 #include <iostream> 
#include <vector> 
using namespace std; 
 
int majorityElement(vector<int>& nums) { 
    int m = nums[0], freq=1; 
 
    for(int i=1; i<nums.size(); i++) { 
        if(freq==0) { 
            m = nums[i]; 
            freq = 1; 
        } 
        else if(m == nums[i]) freq++; 
        else freq--; 
    } 
    return m; 
} 
 
int main() { 
    int n; 
    cout<<"Enter the number of elements: "; 
    cin>>n; 
    vector<int> nums(n); 
    cout<<"Enter the elements: "; 
    for(int i=0; i<n; i++) cin>>nums[i]; 
    cout<<"Majority Element: "<<majorityElement(nums)<<endl; 
    return 0; 
}