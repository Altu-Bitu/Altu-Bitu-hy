
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    vector<stack<int>> doll(n);

    //스택에 인형 종류 입력
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(board[i][j] != 0)
                doll[j].push(board[i][j]);
        }
    }

    stack<int> moved;
    int prev = 0;
    //인형 옮기기
    for(int move : moves){
        if(doll[move-1].empty())
            continue;
        int k = doll[move-1].top();
        doll[move-1].pop();
        if(k==prev){ //연속해서 쌓였다면
            moved.pop();
            //바구니가 비지 않았다면 마지막 값 입력, 비었다면 0 입력
            if(!moved.empty()){
                prev = moved.top();
            }
            else{
                prev = 0;
            }
            answer += 2;
        }
        else{
            moved.push(k);
            prev = k;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    cout << solution(board, moves);
}