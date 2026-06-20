
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dfs(vector<int>adj[] , vector<int> &vis , int s,int d){
    if(s==d) return true;
    vis[s] = 1;
    for(auto it : adj[s]){
        if(vis[it] == 0){
            if(dfs(adj , vis, it,d)){
                return true;
            }
            
        }
    }
    return false;

}

int main(){
    int v,e ;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;
    vector<int>adj[v+1];
    cout<<"enter all of the source and destination node : ";
    for(int i = 0 ; i< e ; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>vis(v+1,0);
    int s,d;
    cout<<"enter the source node and destination node";
    cin >> s >>d;
    if(dfs(adj , vis,s,d)){
        cout<<"Yes! path Exist";
    }else{
        cout<<"No path Exist";
    }


}