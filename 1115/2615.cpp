#include <iostream>
#include <vector>

using namespace std;

bool five(int color, int i, int j, vector<vector<int>> board){
    bool check = true;
    for(int k = 1; k < 5; k++){
        if(j>15 || board[i][j+k] != color){
            check = false;
            break;
        }
    }
    if(check){
        if((j==1 || board[i][j-1] != color) && (j==15 || board[i][j+5] != color))
            return true;
    }

    check = true;
    for (int k = 1; k < 5; k++) {
        if(i>15 || board[i+k][j] != color){
            check = false;
            break;
        }
    }
    if(check){
        if((i==1 || board[i-1][j] != color) && (i==15 || board[i+5][j] != color))
            return true;
    }

    check = true;
    for(int k = 1; k < 5; k++){
        if(i>15 || j>15 || board[i+k][j+k] != color){
            check = false;
            break;
        }
    }
    if(check){
        if((i==1 || j==1 || board[i-1][j-1] != color) && (i==15 || j==15 || board[i+5][j+5] != color))
            return true;
    }

    check = true;
    for(int k=1; k<5; k++){
        if(i<5 || j>15 || board[i-k][j+k] != color){
            check = false;
            break;
        }
    }
    if(check){
        if((i==1 || j==19 || board[i+1][j-1] != color) && (i==5 || j==15 || board[i-5][j+5] != color))
            return true;
    }

    return false;

}

int main() {

    vector<vector<int>> board(20, vector<int>(20));
    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            cin >> board[i][j];
        }
    }

    bool check;
    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            int color = board[i][j];
            if(color == 1) {
                check = five(1, i, j, board);
                if(check) {
                    cout << color << '\n' << i << ' ' << j;
                    return 0;
                }
            }
            else if(color == 2){
                check = five(2, i, j, board);
                if(check){
                    cout << color << '\n' << i << ' ' << j;
                    return 0;
                }
            }
        }
    }

    cout << 0;
    return 0;

}
