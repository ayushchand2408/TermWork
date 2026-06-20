#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<int>graph[], int v) {
    vector<int> color(v + 1, -1); 
    queue<int> q;
    for (int i = 1; i <= v; i++) {
        if (color[i] == -1) { 
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {   
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {  
                        return false;  
                    }
                }
            }
        }
    }
    return true;  
}
int main() {
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;
    vector<int> adj[v+1]; 
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }
    if (isBipartite(adj, v)) {  
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }
    return 0;
}