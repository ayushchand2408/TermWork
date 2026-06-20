#include <iostream> 
#include <vector> 
#include <unordered_map> 
using namespace std; 
 
void findPairs(vector<int>& arr, int n) { 
    bool found = false; 
    unordered_map<int, pair < int, int > > H; 
    for (int i=0; i<n; i++) { 
        for (int j=i+1; j<n; j++) { 
 
            int prod = arr[i]*arr[j]; 
            if (H.find(prod) == H.end()) 
                H[prod] = make_pair(i,j); 
            else { 
                pair<int,int> pp = H[prod]; 
                cout << arr[pp.first] << " " << arr[pp.second]<< " and " << arr[i]<<" "<<arr[j]<<endl; 
                found = true; 
            } 
        } 
    } 
 
    if (found == false) 
        cout << "No pairs Found" << endl; 
} 
 
int main() 
{ 
    int n, k; 
    cout<<"Enter the number of elements:"; 
    cin>>n; 
    vector<int> nums(n); 
    cout<<"Enter the elements of the array:"; 
    for(int i=0; i<n; i++) cin>>nums[i]; 
    findPairs(nums,n); 
    cout<<endl; 
    return 0; 
} 
