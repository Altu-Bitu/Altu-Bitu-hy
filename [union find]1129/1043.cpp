//
// Created by LG on 2021-11-27.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<bool> truth;

int findParent(int node){
    if(parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp)
        return;
    if(truth[xp] || truth[yp])
        truth[xp] = truth[yp] = true;
    if(parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = m;
    parent.assign(n+1, -1);
    truth.assign(n+1, false);
    vector<vector<int>> party(m, vector<int>());

    for(int i=0; i<k; i++){
        int p;
        cin >> p;
        truth[p] = true;
    }

    for(int i=0; i<m; i++){
        int t;
        cin >> t;
        party[i].assign(t, 0);

        for(int j=0; j<t; j++){
            int p;
            cin >> p;
            party[i][j] = p;
        }

        for(int j=0; j<t; j++){
            for(int l=j+1; l<t; l++)
                unionInput(party[i][j], party[i][l]);
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<party[i].size(); j++){
            if(truth[findParent(party[i][j])]){
                cnt--;
                break;
            }
        }
    }

    cout << cnt;
    return 0;
}
