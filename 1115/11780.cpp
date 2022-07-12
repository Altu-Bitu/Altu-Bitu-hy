//
// Created by LG on 2021-11-13.
//
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;
typedef pair<int, int> ci;

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<ci>> &table){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int dist = graph[i][k] + graph[k][j];
                if(dist < graph[i][j]){
                    graph[i][j] = dist;
                    table[i][j] = {table[i][k].first+table[k][j].first, table[i][k].second};
                }
            }
        }
    }
}

int main(){

    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    vector<vector<ci>> table(n+1, vector<ci>(n+1));
    for(int i=1; i<=n; i++)
        graph[i][i] = 0;

    while(m--){
        cin >> a >> b >> c;
        if(graph[a][b] > c){
            graph[a][b] = c;
            table[a][b] = {1, b};
        }
    }

    floydWarshall(n, graph, table);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] == INF)
                cout << '0' << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] == INF || graph[i][j] == 0)
                cout << '0';
            else{
                cout << table[i][j].first+1 << ' ' << i << ' ';
                int t = table[i][j].second;
                while(t != j){
                    cout << t << ' ';
                    t = table[t][j].second;
                }
                cout << j;
            }
            cout << '\n';
        }
    }
}
