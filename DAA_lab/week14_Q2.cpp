#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std; 
 
class Graph { 
    int V; 
    vector<vector<int>> adj; 
 
    void DFSUtil(int v, vector<bool> &visited) { 
        visited[v] = true; 
        for (int i : adj[v]) 
            if (!visited[i]) 
                DFSUtil(i, visited); 
    } 
 
public: 
    Graph(int V) { 
        this->V = V; 
        adj.resize(V); 
    } 
 
    void addEdge(int u, int v) { 
        adj[u].push_back(v); 
    } 
 
    int findMotherVertex() { 
        vector<bool> visited(V, false); 
        int candidate = -1; 
 
        for (int i = 0; i < V; i++) { 
            if (!visited[i]) { 
                DFSUtil(i, visited); 
                candidate = i; 
            } 
        } 
 
        fill(visited.begin(), visited.end(), false); 
        DFSUtil(candidate, visited); 
 
        for (bool v : visited) 
            if (!v) 
                return -1;  
        return candidate;
                 
    } 
}; 
 
int main() { 
    int V, E; 
    cout<<"Enter the number of Vertices and Edges:"; 
    cin >> V >> E; 
 
    Graph g(V); 
    for (int i = 0; i < E; i++) { 
        cout<<"Enter the source and destination:"; 
        int u, v; 
        cin >> u >> v; 
        g.addEdge(u, v); 
    } 
 
    int mother = g.findMotherVertex(); 
    if (mother == -1) 
        cout << "\nNo Mother Vertex" << endl; 
    else 
        cout << "\nMother Vertex is: " << mother<< endl; 
    return 0; 
} 