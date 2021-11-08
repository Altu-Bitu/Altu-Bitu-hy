//
// Created by LG on 2021-11-07.
//
#include <iostream>

using namespace std;

void move(string dir, int &r, int &c){

    if(dir == "R"){
        r += 0;
        c += 1;
    }
    else if(dir == "L"){
        r += 0;
        c += -1;
    }
    else if(dir == "B"){
        r += -1;
        c += 0;
    }
    else if(dir == "T"){
        r += 1;
        c += 0;
    }
    else if(dir == "RT"){
        r += 1;
        c += 1;
    }
    else if(dir == "LT"){
        r += 1;
        c += -1;
    }
    else if(dir == "RB"){
        r += -1;
        c += 1;
    }
    else{
        r += -1;
        c += -1;
    }
}

int main(){
    int r_king, c_king, r_rock, c_rock, n;
    string king, rock;
    cin >> king >> rock >> n;

    r_king = king[1]-'0';
    c_king = king[0] - 'A';
    r_rock = rock[1]-'0';
    c_rock = rock[0] - 'A';

    while(n--){
        string dir;
        cin >> dir;
        int r_temp = r_king;
        int c_temp = c_king;
        move(dir, r_temp, c_temp);
        if(r_temp < 1 || r_temp > 8 || c_temp < 0 || c_temp > 7)
            continue;
        if(r_temp == r_rock && c_temp == c_rock){
            int r_rocktemp = r_rock;
            int c_rocktemp = c_rock;
            move(dir, r_rocktemp, c_rocktemp);
            if(r_rocktemp < 1 || r_rocktemp > 8 || c_rocktemp < 0 || c_rocktemp > 7)
                continue;
            r_rock = r_rocktemp;
            c_rock = c_rocktemp;
        }
        r_king = r_temp;
        c_king = c_temp;
    }

    cout << char(c_king + 'A') << r_king << '\n';
    cout << char(c_rock + 'A') << r_rock;

    return 0;
}
