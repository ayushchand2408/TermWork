#include <iostream> 
#include <vector> 
using namespace std; 
 
int minCostMultiply(vector<int>& dim, int i, int j) { 
    if(i>=j) return 0; 
 
    int ans = INT32_MAX; 
    for(int k=i; k<j; k++) { 
        int temp =  minCostMultiply(dim,i,k) + minCostMultiply(dim,k+1,j) + dim[i-1]*dim[k]*dim[j]; 
        ans = min(ans,temp); 
    } 
    return ans; 
} 
 
int returnMinCost(vector<vector<int>>& matDim, int n) { 
    vector<int> dim(n+1); 
 
    dim[0] =  matDim[0][0]; 
    dim[1] = matDim[0][1]; 
 
    for(int i=2; i<n+1; i++) { 
        dim[i] = matDim[i-1][1]; 
    } 
 
    return minCostMultiply(dim,1,n); 
} 
 
int main() { 
    int n; 
    cout<<"Enter the number of matrices: "; 
    cin>>n; 
    vector<vector<int>> matDim(n,vector<int>(2)); 
    for(int i=0; i<n; i++) { 
        cout<<"Enter the dimension of matrix"<<i+1<<":"; 
        cin>>matDim[i][0]>>matDim[i][1]; 
    } 
    cout<<"Minimum cost :"<<returnMinCost(matDim,n)<<"\n"<<endl; 
    return 0; 
}