//
// Created by LG on 2021-11-20.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, q, t, k;
    cin >> n;
    vector<int> tree(n+1);
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        tree[a]++;
        tree[b]++;
    }

    cin >> q;
    while(q--){
        cin >> t >> k;
        if(t==1 && tree[k] == 1)
            cout << "no\n";
        else
            cout << "yes\n";
    }

}
