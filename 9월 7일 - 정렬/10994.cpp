
#include <iostream>
#include <vector>

using namespace std;

void solve(int x, int y, int start_len, int length, vector<vector<char>> &star){

    if(x == start_len / 2  && y == start_len / 2){
        star[x][y] = '*';
        return;
    }

    for(int i=x; i<x+length; i++){
        star[i][y] = '*';
        star[i][y+length-1] = '*';
        star[x][i] = '*';
        star[x+length-1][i] = '*';
    }

    solve(x+2, y+2, start_len, length-4, star);
}

int main(){
    int n;
    cin >> n;
    int length = 4*n-3;

    vector<vector<char>> star(length,vector<char>(length, ' '));

    solve(0, 0, length, length, star);

    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++)
            cout << star[i][j];
        cout << '\n';
    }
}


