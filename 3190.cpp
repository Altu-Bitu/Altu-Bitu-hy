//
// Created by LG on 2021-10-02.
//
#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

struct info{
    int r, c;
};

int n;
map<int, char> change;
info head = {1, 1};

//동서남북 방향 전환 함수
char changeDir(char from, char to){
    if(from == 'E'){
        if(to == 'L')
            return 'N';
        else
            return 'S';
    }
    else if(from == 'W'){
        if(to == 'L')
            return 'S';
        else
            return 'N';
    }
    else if(from == 'S'){
        if(to == 'L')
            return 'E';
        else
            return 'W';
    }
    else{
        if(to == 'L')
            return 'W';
        else
            return 'E';
    }
}

//방향에 따라 머리 이동하고 종료 결정
void moveHead(char &dir, bool &fin, vector<vector<bool>> &check, deque<info> &snake, int &cnt){
    //방향 바꿔야 할 초이면 방향을 바꿈
    if(change.find(cnt-1) != change.end())
        dir = changeDir(dir, change[cnt-1]);

    if(dir == 'E')
        head.c++;
    else if(dir == 'W')
        head.c--;
    else if(dir == 'S')
        head.r++;
    else
        head.r--;

    //벽이나 몸통에 닿지 않았으면 머리 더함.
    if(head.r > 0 && head.r <= n && head.c > 0 && head.c <=n &&!check[head.r][head.c]){
        snake.push_front({head.r, head.c});
        check[head.r][head.c] = true;
        //cout << "cnt:" << cnt << ' ' << "r:" << head.r << ' ' << "c:" << head.c << '\n';
    }
    else{
        fin = true;
    }
}

int main(){
    int k, l, cnt = 1;
    cin >> n >> k;
    deque<info> snake;
    vector<vector<bool>> check(n+1, vector<bool>(n+1, false));
    vector<vector<bool>> apple(n+1, vector<bool>(n+1, false));

    //사과 위치 입력
    for(int i=1; i<=k; i++){
        int r, c;
        cin >> r >> c;
        apple[r][c] = true;
    }

    //방향 전환 정보 입력
    cin >> l;
    for(int i=0; i<l; i++){
        int sec;
        char dir;
        cin >> sec >> dir;
        change.insert(pair<int, char>(sec, dir)); //!insert(make_pair(sec, dir));
    }

    char dir = 'E';
    snake.push_back({1, 1});
    check[1][1] = true;
    bool fin = false;
    while(true){
        moveHead(dir, fin, check, snake, cnt);
        if(fin)
            break;
        //사과 먹었는지에 따라 꼬리 없애거나 사과 없앰.
        if(!apple[head.r][head.c]){
            info t = snake.back();
            snake.pop_back();
            check[t.r][t.c] = false;
        }
        else{
            apple[head.r][head.c] = false;
        }
        cnt++;
    }

    cout << cnt;
}
