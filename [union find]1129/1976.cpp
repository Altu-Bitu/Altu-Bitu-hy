//
// Created by LG on 2021-11-28.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node){
    if(parent[node] < 0)
        return node;
    else
        return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp)
        return;
    if(parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{
        parent[yp] +=  parent[xp];
        parent[xp] = yp;
    }

}

bool result(int m, vector<int> route){
    for(int i=0; i<m-1; i++){
        int p1 = findParent(route[i]);
        int p2 = findParent(route[i+1]);
        if(p1 != p2)
            return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    parent.assign(n+1, -1);
    vector<vector<int>> cities(n+1, vector<int>(n+1));
    vector<int> route(m, 0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> cities[i][j];
        }
    }

    for(int i=0; i<m; i++){
        cin >> route[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(cities[i][j]==1)
                unionInput(i, j);
        }
    }

    if(result(m, route))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
