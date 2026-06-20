#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> dijkastras(vector<vector<pair<int,int>>>& adj , int start , int v)
{
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> dist(v+1 , INT_MAX);
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()){
        int curr_node = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(curr_node > dist[u]) continue;
        for(auto it  : adj[u]){
            int w = it.second;
            int node = it.first;
            if(dist[node] > w + curr_node){
                dist[node] = w + curr_node;
                pq.push({dist[node],node});
            }
        }
    }
    return dist;
}
int main(){
    int v , e;
    cout<<"enter the number of vertices and edges :- ";
    cin >> v >> e;

    vector<vector<pair<int,int>>> adj(v+1);
   
    cout<<"enter the source , destination and weight :- ";
    for(int i = 0 ; i < e ; i++){
        int s , d , w;
        cin >> s >> d >> w;
        adj[s].push_back({d,w});
        adj[d].push_back({s,w});
    }

    int start;
    cout<< "enter start index :- ";
    cin >> start;
    vector<int> distance = dijkastras(adj,start,v);

    cout << "\nShortest distances from node " << start << ":\n";
    for (int i = 1; i <= v; i++) { 
        cout << "To node " << i << ": " << distance[i] << endl;
    }

}