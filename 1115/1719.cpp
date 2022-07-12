//
// Created by LG on 2021-11-13.
//
#include <iostream>
#include <vector>

using namespace std;

const int INF = 2*1e5;

void floydWarshall(int n, vector<vector<int>> graph, vector<vector<int>> &table){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int dist = graph[i][k] + graph[k][j];
                if(dist < graph[i][j]){
                    graph[i][j] = dist;
                    table[i][j] = table[i][k];
                }
            }
        }
    }
}

int main(){
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    vector<vector<int>> table(n+1, vector<int>(n+1));
    for(int i=0; i<n; i++)
        graph[i][i] = 0;

    while(m--){
        cin >> u >> v >> w;
        if(graph[u][v] > w){
            graph[u][v] = w;
            graph[v][u] = w;
            table[u][v] = v;
            table[v][u] = u;
        }
    }

    floydWarshall(n, graph, table);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                cout << '-' << ' ';
            else
                cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
}
