//
// Created by LG on 2021-11-07.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool check [101][101] = {false, };

    while(n--){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<int> dragon;
        check[x][y] = true;
        x += dx[d];
        y += dy[d];
        check[x][y] = true;
        dragon.push_back(d);
        for(int i=0; i<g; i++){
            for(int j=(1<<i)-1; j>=0; j--){
                int t = (dragon[j]+1)%4;
                x += dx[t];
                y += dy[t];
                check[x][y] = true;
                dragon.push_back(t);
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1])
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}
