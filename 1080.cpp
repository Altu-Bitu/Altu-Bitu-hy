//
// Created by LG on 2021-10-05.
//
#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool compare(vector<vector<bool>> m1, vector<vector<bool>> m2){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(m1[i][j] != m2[i][j])
                return false;
        }
    }
    return true;
}

int find(vector<vector<bool>> &m1, vector<vector<bool>> m2){
    int cnt = 0;
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-2; j++){
            if(m1[i][j] != m2[i][j]) {
                for(int k=0; k<3; k++) {
                    for(int p=0; p<3; p++)
                        m1[i+k][j+p] = !m1[i+k][j+p];
                }
                cnt++;
                if(compare(m1, m2))
                    return cnt;
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;

    vector<vector<bool>> m1(n, vector<bool>(m, 0));
    vector<vector<bool>> m2(n, vector<bool>(m, 0));

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            int t = s[j] - '0';
            m1[i][j] = t;
        }
    }

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            int t = s[j] - '0';
            m2[i][j] = t;
        }
    }

    if(compare(m1, m2))
        cout << 0;
    else{
        if(n<3 || m<3)
            cout << -1;
        else
            cout << find(m1, m2);
    }

}
