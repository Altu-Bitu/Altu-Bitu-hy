//
// Created by LG on 2021-12-05.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

int findParent(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp)
        return false;
    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

long long kruskal(int v, priority_queue<tp, vector<tp>, greater<>> &pq){
    int cnt = 0;
    int sum = 0;

    while(cnt < v-1){
        if(pq.empty())
            return 0;
        int weight = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if(unionInput(x, y)){
            cnt++;
            sum += weight;
        }
    }

    return sum;
}

int main(){
    int n, m, a, b, w;
    cin >> n >> m;
    priority_queue<tp, vector<tp>, greater<>> pq;

    parent.assign(n+1, -1);
    long long total = 0;
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        total += w;
        pq.push({w, a, b});
    }

    long long cost = kruskal(n, pq);
    if(cost == 0)
        cout << -1;
    else
        cout << total - cost;

    return 0;
}