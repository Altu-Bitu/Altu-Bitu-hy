//
// Created by LG on 2021-12-05.
//
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

typedef pair<int, int> ci;
typedef tuple<double, int, int> tp;

vector<int> parent;
double sum;

int findParent(int node){
    if(parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp)
        return false;
    if(parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

double kruskal(int v, priority_queue<tp, vector<tp>, greater<>> &pq){
    int cnt = 0;

    while(cnt < v-1){
        double weight = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if(unionInput(x, y)){
            sum += weight;
            cnt++;
        }
    }
    return sum;
}

int main(){

    int n, m;
    cin >> n >> m;
    parent.assign(n+1, -1);
    priority_queue<tp, vector<tp>, greater<>> pq;
    priority_queue<tp, vector<tp>, greater<>> pq_cycle;

    vector<vector<bool>> connected(n+1, vector<bool>(n+1, false));
    vector<ci> god(n+1);
    for(int i=1; i<=n; i++){
        cin >> god[i].first >> god[i].second;
    }

    int cnt = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        connected[a][b] = true;

        int xp = findParent(a);
        int yp = findParent(b);

        if(xp != yp){
            if (parent[xp] < parent[yp]) {
                parent[xp] += parent[yp];
                parent[yp] = xp;
            }
            else {
                parent[yp] += parent[xp];
                parent[xp] = yp;
            }
            cnt++;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            double xd = god[i].first - god[j].first;
            double yd = god[i].second - god[j].second;
            if(connected[i][j] || connected[j][i])
                continue;
            else
                pq.push({sqrt(xd*xd+yd*yd), i, j});
        }
    }

    kruskal(n-cnt, pq);
    cout << fixed;
    cout.precision(2);
    cout << sum;

    return 0;
}
