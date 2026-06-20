#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
 
int find(int u, vector<int>& parent) { 
    if(parent[u]==u) return u; 
    return parent[u] = find(parent[u],parent); 
} 
 
void unionNode(int u, int v, vector<int>& parent, vector<int>& rank) { 
    int up = find(u, parent); 
    int vp = find(v,parent); 
 
    if(rank[up] > rank[vp]) parent[vp] = up; 
    else if(rank[up] < rank[vp]) parent[up] = vp; 
    else { 
        parent[vp]=up; 
        rank[up]+=1; 
    } 
} 
 
int kruskalSpanningTree(vector<pair<int,pair<int,int>>>& edges,int V) { 
    vector<int> parent(V); 
    vector<int> rank(V,0); 
    for(int i=0; i<V; i++) parent[i]=i; 
 
    sort(edges.rbegin(), edges.rend());  
     
    int cost=0; 
    for(auto edge : edges) { 
        int u = edge.second.first; 
        int v = edge.second.second; 
 
        if(find(u,parent)!=find(v,parent)) { 
            cost+=edge.first; 
            unionNode(u,v,parent,rank); 
        } 
    } 
    return cost; 
} 
 
int main() { 
    int V,E; 
    cout<<"Enter the number of vertices & edges:"; 
    cin>>V>>E; 
 
    vector<pair<int,pair<int,int>>> adj(V); 
    for(int i=0; i<E; i++) { 
        int cost, u, v; 
        cout<<"Enter the source, destination and cost:"; 
        cin>>u>>v>>cost; 
        adj.push_back({cost,{u,v}}); 
    } 
    cout<<"Maximum cost of traversing the graph: "<<kruskalSpanningTree(adj,V); 
    return 0; 
}