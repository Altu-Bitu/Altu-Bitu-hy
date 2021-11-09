//
// Created by LG on 2021-11-07.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5;

vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph){
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[1] = start;
    pq.push({start, 1});

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node])
            continue;
        for(int i=0; i<graph[node].size(); i++){
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if(dist[next_node] > next_weight){
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;

}

int main(){

    int n;
    cin >> n;
    int t = 1;
    while(n != 0){
        vector<int> matrix(n*n+1);
        for(int i=1; i<=n*n; i++){
            cin >> matrix[i];
        }

        vector<vector<ci>> graph(n*n+1, vector<ci>(0));
        for(int i=1; i<n; i++){
            graph[i].emplace_back(i+1, matrix[i+1]);
            graph[i].emplace_back(i+n, matrix[i+n]);
        }
        for(int i=n+1; i<=n*n-n; i++){
            if(i%n == 1){
                graph[i].emplace_back(i+1, matrix[i+1]);
                graph[i].emplace_back(i+n, matrix[i+n]);
                graph[i].emplace_back(i-n, matrix[i-n]);
            }
            else if(i%n == 0){
                graph[i].emplace_back(i-1, matrix[i-1]);
                graph[i].emplace_back(i+n, matrix[i+n]);
                graph[i].emplace_back(i-n, matrix[i-n]);
            }
            else{
                graph[i].emplace_back(i-1, matrix[i-1]);
                graph[i].emplace_back(i+1, matrix[i+1]);
                graph[i].emplace_back(i+n, matrix[i+n]);
                graph[i].emplace_back(i-n, matrix[i-n]);
            }
        }
        for(int i=n*n-n; i<n*n; i++){
            graph[i].emplace_back(i-n, matrix[i-n]);
            graph[i].emplace_back(i+1, matrix[i+1]);
        }
        graph[n].emplace_back(2*n, matrix[2*n]);

        vector<int> ans = dijkstra(n*n, matrix[1], graph);
        cout << "Problem " << t << ": " << ans[n*n] << '\n';
        t++;
        cin >> n;
    }

}
