//
// Created by LG on 2021-11-28.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = INT_MAX;

int main(){
    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> height(n, vector<int>(m, 0));
    int min_h = 256;
    int max_h = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> height[i][j];
            if(height[i][j] < min_h)
                min_h = height[i][j];
            if(height[i][j] > max_h)
                max_h = height[i][j];
        }
    }

    int ans_time = MAX;
    int ans_h;
    while(min_h <= max_h){
        int time = 0;
        int b_temp = b;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(height[i][j] > min_h){
                    int diff = height[i][j] - min_h;
                    time += 2*diff;
                    b_temp += diff;
                }
                else if(height[i][j] < min_h){
                    int diff = min_h - height[i][j];
                    time += diff;
                    b_temp -= diff;
                }
            }
        }

        if(b_temp >= 0 && time <= ans_time) {
            ans_time = time;
            ans_h = min_h;
        }
        min_h++;
    }

    cout << ans_time << ' ' << ans_h;
    return 0;
}
