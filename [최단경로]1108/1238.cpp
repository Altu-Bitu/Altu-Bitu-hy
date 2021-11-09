//
// Created by LG on 2021-11-07.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5*2;

vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph){
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

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
    int n, m, x, u, v, w;
    cin >> n >> m >> x;

    vector<vector<ci>> graph(n+1, vector<ci>(0));
    while(m--){
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); //u에서 v로 가는 가중치 w인 간선
    }

    vector<int> back = dijkstra(n, x, graph);
    vector<vector<int>> go(n+1, vector<int>());
    for(int i=1; i<=n; i++){
        go[i] = dijkstra(n, i, graph);
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(go[i][x] + back[i], ans);
    }
    cout << ans;
}
