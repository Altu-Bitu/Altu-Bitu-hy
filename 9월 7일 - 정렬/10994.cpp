
#include <iostream>

using namespace std;

void solve(int x, int y, int start_len, int length, char star[][400]){

    if(x == start_len / 2  && y == start_len / 2){
        star[x][y] = '*';
        return;
    }

    for(int i=x; i<x+length; i++){
        if(i==x || i==x+length-1){
            for(int j=y; j<y+length; j++){
                star[i][j] = '*';
            }
        }
        else{
            star[i][y] = '*';
            star[i][y+length-1] = '*';
        }
    }

    solve(x+2, y+2, start_len, length-4, star);
}

int main(){
    int n;
    cin >> n;
    int length = 1+(n-1)*4;

    char star[400][400];

    solve(0, 0, length, length, star);

    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(star[i][j] == '*'){
                cout << star[i][j];
            }
            else
                cout << " ";
        }
        cout << '\n';
    }
}


