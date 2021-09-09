
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &i1, const pair<int, int> &i2){
    if(i1.second != i2.second)
        return i1.second < i2.second;
    return i1.first < i2.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);

    for(int i=0; i<n; i++){
        cin >> xy[i].first >> xy[i].second;
    }

    sort(xy.begin(), xy.end(), comp);

    for(int i=0; i<n; i++){
        cout << xy[i].first << " " << xy[i].second << '\n';
    }
}
