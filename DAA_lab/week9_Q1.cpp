#include <iostream> 
#include <vector> 
using namespace std; 
 
vector<vector<int>> inputGraph(int V, int E) { 
    vector<vector<int>> mat(V,vector<int>(V,INT32_MAX)); 
    int src, dst, cost; 
 
    for(int i=0; i<E; i++) { 
        cout<<"Enter the source, destination and cost:"; 
        cin>>src>>dst>>cost; 
        mat[src][dst] = cost; 
    } 
 
    for(int i=0; i<V; i++)  mat[i][i]=0; 
    return mat; 
} 
 
void floydWarshell(vector<vector<int>>& mat, int V) { 
    for(int k=0; k<V; k++) { 
        for(int i=0; i<V; i++) { 
            for(int j=0; j<V; j++ ){ 
 
                if(mat[i][k]==INT32_MAX || mat[k][j]==INT32_MAX) continue; 
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]); 
            } 
        } 
    } 
} 
 
void display(const vector<vector<int>>& mat, int V) { 
    for(int i=0; i<V; i++) { 
        for(int j=0; j<V; j++) 
            cout<<((mat[i][j]!=INT32_MAX)?mat[i][j]:-1)<<" "; 
        cout<<endl; 
    } 
} 
 
int main() { 
    int V,E; 
    cout<<"Enter the number of nodes and edges:"; 
    cin>>V>>E; 
    vector<vector<int>> mat = inputGraph(V,E); 
    floydWarshell(mat,V); 
    display(mat,V); 
    return 0; 
}