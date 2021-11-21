//
// Created by LG on 2021-11-20.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tree;
vector<int> sizee;

void makeTree(int currentNode, int parent){
    for(int i=0; i<graph[currentNode].size(); i++){
        if(graph[currentNode][i] != parent) {
            tree[currentNode].push_back(graph[currentNode][i]);
            makeTree(graph[currentNode][i], currentNode);
        }
    }
}

void countSubtreeNodes(int currentNode){
    sizee[currentNode] = 1;
    for(int i=0; i<tree[currentNode].size(); i++){
        countSubtreeNodes(tree[currentNode][i]);
        sizee[currentNode] += sizee[tree[currentNode][i]];
    }
}

int main(){
    int n, r, q, u, v;
    cin >> n >> r >> q;
    graph.assign(n+1, vector<int>(0));
    tree.assign(n+1, vector<int>(0));
    sizee.assign(n+1, 0);

    n--;
    while(n--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    makeTree(r, -1);
    countSubtreeNodes(r);

    while(q--){
        cin >> u;
        cout << sizee[u] << '\n';
    }

    return 0;
}
