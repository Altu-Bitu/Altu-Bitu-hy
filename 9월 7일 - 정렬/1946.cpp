
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    vector<pair<int, int>> v;
    v.assign(n, {});

    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int count = n;
    int temp = v[0].second;
    for(int i=1; i<n; i++){
        if(v[i].second > temp)
            count--;
        else
            temp = v[i].second;
    }

    return count;

}

int main(){
    int t;
    cin >> t;

    int answer[t];

    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        answer[i] = solution(n);
    }

    for(int i=0; i<t; i++){
        cout << answer[i] << '\n';
    }
}

