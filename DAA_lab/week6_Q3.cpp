#include<iostream>
#include<vector>
using namespace std;

bool detectCycle (vector<int> adj[] , vector<int> & vis , int s , int parent){
    vis[s]=1;
    for(auto it : adj[s])
        if(vis[it] == 0)
            detectCycle(adj,vis,it,s);
        else
            if(it != parent)
                return true;
    return false; 
}
int main(){
    int v,e ,s,d;
    cout<<"enter the vertices and edges : ";
    cin >> v >> e;
    vector<int>adj[v+1],vis(v+1);
    for(int i = 0 ; i< e ; i++){
        cin >> s >> d;
        adj[s].push_back(d);
        adj[d].push_back(d);
    }
    cout<<"enter the source node : ";
    cin >> s;
    if(detectCycle(adj,vis,s,-1))
        cout<<"Cycle Deteced...........";
    else
        cout<<"No Cycle Detected............";
}