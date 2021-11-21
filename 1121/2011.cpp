//
// Created by LG on 2021-11-17.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> pw;
long long dp[5001];
int len;

int find(){

    if(pw[0] == 0)
        return 0;
    dp[0] = 1;

    if(pw[1] == 0) {
        if (pw[0] < 3)
            dp[1] = 1;
    }
    else{
        if(pw[0] == 1 || (pw[0] == 2 && pw[1] < 7))
            dp[1] = 2;
        else
            dp[1] = 1;
    }

    for(int i=2; i<len; i++){
        if(pw[i] == 0){
            if(pw[i-1] < 3 && pw[i-1] != 0)
                dp[i] = dp[i-2];
            else
                return 0;
        }
        else{
            if(pw[i-1] == 0)
                    dp[i] = dp[i - 1];
            else if(pw[i-1] == 1 || (pw[i-1] ==2 && pw[i] < 7))
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
    }

    return dp[len-1]%1000000;
}

int main(){
    string s;
    cin >> s;
    len = s.length();
    for(int i=0; i<len; i++){
        pw.push_back(s[i]-'0');
    }
    cout << find();

}
