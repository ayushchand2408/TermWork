#include <iostream> 
#include <vector> 
using namespace std; 
 
int maxKnapSack(vector<int>& wt, vector<int>& value, vector<vector<int>> mat,int 
capacity, int index) { 
    if( capacity <=0 || index<0) return 0; 
 
    if(mat[index][capacity]!=-1)  
        return mat[index][capacity]; 
 
    if(wt[index] > capacity)  
        return  mat[index][capacity] = (wt,value,mat,capacity,index-1); 
 
    int w1 = value[index] + maxKnapSack(wt,value,mat,capacity-wt[index],index-1); 
 
    int w2 = maxKnapSack(wt,value,mat,capacity,index-1); 
 
    return mat[index][capacity] = max(w1,w2); 
} 
 
int main() { 
    int n,w; 
    cout<<"Enter the number of values:"; 
    cin>>n; 
    vector<int> value(n), wt(n); 
    cout<<"Enter the weights: "; 
    for(int i=0; i<n; i++)  
        cin>>wt[i]; 
    cout<<"Enter the values: "; 
    for(int i=0; i<n; i++)  
        cin>>value[i]; 
    cout<<":Enter the capacity of the bag: "; 
    cin>>w; 
    vector<vector<int>> mat(n,vector<int>(w+1,-1)); 
    cout<<"Maximum value retrived: "<<maxKnapSack(wt,value,mat,w,n-1)<<endl; 
    return 0; 
} 