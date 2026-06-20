#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int s , vector<vector<int>> & matrix , int v,vector<int> &vis){
    cout<<s<<" ";
    vis[s]=1;
    for(int i = 0 ; i <=v ;i++){
        if(matrix[s][i] && vis[i]==0){
            dfs(i,matrix,v,vis);
        }
    }
    
}
int main(){
    int e,v;
    cin >> v >> e;
    vector<vector<int>> matrix(v+1,vector<int>(v+1));
    for(int i = 0 ;i <= v ; i++){
        for(int j = 0 ; j <= v ; j++){
            // if(i == j ){
            //     matrix[i][j]=1;
            // }else{
                matrix[i][j] = 0;
            //}
           
        }
    }
    for(int i = 0 ;i <e ; i++){
        int u,v;
        cin >> u>>v;
        matrix[u][v]=1;
        matrix[v][u]=1;
    }

    cout<<endl;
    for(int i = 0 ; i <= v ; i++){
        for(int j = 0 ; j <= v ;j++){
            if(matrix[i][j] == 1){
                cout << i << "--->" <<j <<endl;
            }
            // cout<<matrix[i][j] << " ";
        }
        // cout<<endl;
    }
    //BFS
    // queue<int>q;
    vector<int>vis(v+1,0);
    int s;
    cin >> s;
    // q.push(s);
    // vis[s] = 1;
    // while(!q.empty()){
    //     int f = q.front();
    //     q.pop();
    //     cout<<f << " ";
    //     for(int i = 0; i <=v ; i++)
    //     {
    //         if(matrix[f][i] && vis[i] == 0){
    //             q.push(i);
    //             vis[i]=1;
    //         }
    //     }
    // }

    //DFS
    dfs(s,matrix , v,vis);
}