//
// Created by LG on 2021-11-20.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, pair<int, int>> tree;
vector<int> preorder;

void divide(int left, int right){
    if(left > right)
        return;
    int root = preorder[left];
    int next = left+1;
    while(preorder[next] < root && next < preorder.size())
        next++;
    divide(left+1, next-1);
    divide(next, right);
    cout << root << '\n';
}
int main(){
    int root, node;
    cin >> root;
    preorder.push_back(root);
    while(cin >> node){
        preorder.push_back(node);
    }
    divide(0, preorder.size()-1);
    return 0;
}
