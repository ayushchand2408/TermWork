#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 
 
vector<pair<int,int>> prims(vector<vector<pair<int,int>>>adj, int V)  { 
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 
    vector<pair<int,int>> output(V); 
    vector<bool> visited(V,false); 
    pq.push({0,{0,-1}}); 
 
    while(!pq.empty()) { 
        int node = pq.top().second.first; 
        int parent = pq.top().second.second; 
        int wt = pq.top().first; 
        pq.pop(); 
 
        if(visited[node]) continue; 
 
        output[node] = {wt,parent}; 
        visited[node]=true; 
 
        for(auto it : adj[node]) { 
            if(!visited[it.first]) { 
                pq.push({it.second,{it.first, node}}); 
            } 
        } 
    } 
    return output; 
} 
 
vector<vector<pair<int,int>>> inputGraph(int V, int E) 
{ 
    vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>()); 
    for(int i=0; i<E; i++) 
    {  
        int u,v,w; 
        cout<<"Enter the source, destination and weight:"; 
        cin>>u>>v>>w; 
        adj[u].push_back({v,w}); 
        adj[v].push_back({u,w}); 
    } 
    return adj; 
} 
 
int main() { 
    int V,E,src; 
    cout<<"Enter the number of nodes: "; 
    cin>>V; 
    cout<<"Enter thr number of edges: "; 
    cin>>E; 
    vector<vector<pair<int,int>>> adj = inputGraph(V,E); 
    vector<pair<int,int>> dist = prims(adj,V); 
    for(int i=0; i<dist.size(); i++) 
        cout<<"node:"<<i<<" parent:"<<dist[i].second<<" cost:"<<dist[i].first<<endl; 
    return 0; 
}