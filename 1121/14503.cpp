//
// Created by LG on 2021-11-17.
//
#include <iostream>
#include <vector>

using namespace std;

int r, c, dir, cnt;

bool check(vector<vector<int>> board, int n, int m){
    int dx[4] = {-1, 0, 1,0};
    int dy[4] = {0, 1, 0, -1}; //왼쪽, 아래, 오른쪽, 위

    for(int i=3; i>=0; i--){
        r += dx[(dir+i)%4];
        c += dy[(dir+i)%4];
        if(r >= 0 && r < n && c >=0 && c < m && board[r][c]==0){
            dir = (dir+i)%4;
            return true;
        }
        r -= dx[(dir+i)%4];
        c -= dy[(dir+i)%4];
    }

    r += dx[(dir+2)%4];
    c += dy[(dir+2)%4];
    if(r < 0 || r >=n || c < 0 || c >=m || board[r][c] == 1){
        r -= dx[(dir+2)%4];
        c -= dy[(dir+2)%4];
        return false;
    }
    else
        check(board, n, m);

    return true;

}

int clean(vector<vector<int>> &board, int n, int m){
    if(board[r][c] == 0){
        board[r][c] = 2;
        cnt++;
    }

    bool flag = check(board, n, m);
    if(flag)
        clean(board, n, m);
    else
        return cnt;

    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m >> r >> c >> dir;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    }

    cout << clean(board, n, m);

}
