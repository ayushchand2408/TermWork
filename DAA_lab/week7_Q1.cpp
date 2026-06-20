#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, int start, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V + 1, INT_MAX); 
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (currentDist > dist[u]) continue; 
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (dist[v] > currentDist + w) {
                dist[v] = currentDist + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<pair<int, int>>> adj(V + 1); 

    cout << "Enter each edge (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    vector<int> distance = dijkstra(V, source, adj);

    cout << "\nShortest distances from node " << source << ":\n";
    for (int i = 1; i <= V; i++) { 
        cout << "To node " << i << ": " << distance[i] << endl;
    }

    return 0;
}