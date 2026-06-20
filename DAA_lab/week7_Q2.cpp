#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 
 
vector<int> bellmanFord(vector<vector<pair<int,int>>>& adj,int V, int src)  
{ 
    vector<int> distance(V,INT32_MAX); 
    distance[src]=0; 
 
    bool changed = false; 
    while(--V)  
    { 
        for(int i=0; i<adj.size(); i++) { 
 
            //if node is itself unreachable 
            if(distance[i]==INT32_MAX) continue; 
             
            for(int j=0; j<adj[i].size(); j++)  
            { 
                int neihgbour = adj[i][j].first; 
                int cost =  adj[i][j].second; 
 
                if(distance[neihgbour] > distance[i]+cost) { 
                    distance[neihgbour]  = distance[i] +cost; 
                    changed=true; 
                } 
            } 
        } 
        if(!changed) return distance; 
    } 
 
    changed = false; 
    //checking for detecting the negative cycle 
    for(int i=0; i<adj.size(); i++) { 
 
        if(distance[i]==INT32_MAX) continue; 
 
        for(int j=0; j<adj[i].size(); j++) { 
 
            int neihgbour = adj[i][j].first; 
            int cost =  adj[i][j].second; 
 
            if(distance[neihgbour] > distance[i]+cost) { 
                distance[neihgbour]  = distance[i] +cost; 
                changed = true; 
            } 
        } 
    } 
 
    if(changed) cout<<"Neagtive cycle detected"<<endl; 
 
    return distance; 
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
    cout<<"Enter the Source Node:"; 
    cin>>src; 
    vector<int> dist = bellmanFord(adj,V,src); 
    for(int i=0; i<dist.size(); i++) 
        cout<<dist[i]<<" "; 
    return 0; 
} 