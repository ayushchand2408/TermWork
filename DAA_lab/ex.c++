#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 20
#define INF 9999

int main() {
    int n;
    int cost[MAX][MAX];

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter the cost matrix (enter 9999 for no direct connection):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for(int src = 0; src < n; src++) {

        int dist[MAX], nextHop[MAX];

        for(int i = 0; i < n; i++) {
            dist[i] = cost[src][i];
            if(cost[src][i] != INF && i != src)
                nextHop[i] = i;      
            else
                nextHop[i] = -1;
        }

        dist[src] = 0;
        nextHop[src] = src;

        for(int k = 0; k < n - 1; k++) {
            for(int u = 0; u < n; u++) {
                for(int v = 0; v < n; v++) {
                    if(dist[u] != INF && cost[u][v] != INF) {
                        if(dist[u] + cost[u][v] < dist[v]) {
                            dist[v] = dist[u] + cost[u][v];
                            nextHop[v] = nextHop[u];
                        }
                    }
                }
            }
        }

        cout << "\nRouting table for Router " << src << ":\n";
        cout << "Destination\tCost\tNext Hop\n";

        for(int i = 0; i < n; i++) {
            cout << i << "\t\t";
            if(dist[i] == INF)
                cout << "INF\t-\n";
            else
                cout << dist[i] << "\t" << nextHop[i] << "\n";
        }
    }

    return 0;
}