// optimize way to store graph
// vector<int> adj[v+1] where v is no of nodes
//for(it i = 0 ; i < ee ; i++){
//int u ,v; cin >> u >> v;
//adj[u].push_back(v);
//adj[v].push_back(u);  ==>  [ [  ] , [   ] , [    ]]
//                               0       1      2        //index
//}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<int>adj[] , vector<int> &vis , int s){
    cout << s << " -- > ";
    vis[s] = 1;
    for(auto it : adj[s]){
        if(vis[it] == 0){
            dfs(adj , vis, it);
        }
    }

}
bool detectCycle (vector<int> adj[] , vector<int> & vis , int s , int parent){
    vis[s]=1;
    for(auto it : adj[s]){
        if(vis[it] == 0){
            detectCycle(adj,vis,it,s);
        }
        else{
            if(it != parent){
                return true;
            }
        }
    }
    
}

int main(){
    int v,e ;
    cin >> v >> e;
    vector<int>adj[v+1];
    for(int i = 0 ; i< e ; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1 ; i <= v ; i++){
        cout << i << "-->";
        for(auto it : adj[i]){//for(int j = 0 ; j < adj[i].size() ; j++)
            cout << it << " ";
        }
        cout<<endl;
    }

    //BFS
    // queue<int>q;
    vector<int>vis(v+1,0);
    // int s;
    // cin >> s;
    // q.push(s);
    // vis[s] = 1;
    // while(!q.empty()){
    //     int f = q.front();
    //     q.pop();
    //     cout<<f << " ";
    //     for(auto it : adj[f])
    //     {
    //         if(adj[f][it] && vis[it] == 0){
    //             q.push(it);
    //             vis[it]=1;
    //         }
    //     }
    // }

    //DFS
    int s;
    cin >> s;
    dfs(adj , vis,s);


}