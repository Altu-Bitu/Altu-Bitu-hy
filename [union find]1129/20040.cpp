//
// Created by LG on 2021-11-27.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node){
    if(parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp){
        return true;
    }
    if(parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return false;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    parent.assign(n, -1);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        if(unionInput(a, b)) {
            cout << i+1;
            return 0;
        }
    }
    cout << '0';
    return 0;
}
