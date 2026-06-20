#include <iostream> 
#include <vector> 
using namespace std; 
 
int dfs(int src, int dst, int k, vector<vector<int>> adj) { 
     
    if(k==0 && src==dst) return 0; 
    if(k==1 && adj[src][dst]!=INT32_MAX) return adj[src][dst]; 
    if(k<0) return INT32_MAX; 
 
    int finalVal = INT32_MAX; 
    for(int i=0; i<adj[src].size(); i++)  
    { 
        if(adj[src][i]!=INT32_MAX && src!=i && dst!=i)  
        { 
            int x = dfs(i,dst,k-1,adj) ;
            if(x!=INT32_MAX) 
                finalVal = min(finalVal,x+adj[src][i]); 
        } 
    } 
    return finalVal; 
} 
 
int main() { 
    int V,E; 
    cout<<"Enter the no. of vertices & Edges: "; 
    cin>>V>>E; 
    vector<vector<int>> matrix(V+1, vector<int>(V+1,INT32_MAX)); 
    int v,e,w,cost; 
    for(int i=0; i<E; i++) { 
        cout<<"Enter the source,destination node & cost: "; 
        cin>>v>>e>>cost; 
        matrix[v][e]=cost; 
    } 
    cout<<"Enter the souce, destination and value of k:"; 
    cin>>v>>e>>w; 
    cout<<"Minimum possible way to reach: "<<dfs(v,e,w,matrix)<<endl; 
    return 0; 
}