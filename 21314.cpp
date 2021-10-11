//
// Created by LG on 2021-10-09.
//
#include <iostream>
#include <vector>

using namespace std;

//M을 많이 끝을수록 숫자가 커지지만 뒤에 K가 있으면 M을 많이 끊을수록 작은 숫자이므로
//뒤에서부터 K가 있으면 다시 K가 나올때까지 끊지 않고 M만 있다면 계속 끊음.
vector<int> findL(vector<char> mink, int n){
    vector<int> ans(n);
    char last = mink[n-1];
    while(n--){
        if(last == 'K'){
            if(n-1 < 0)
                ans[n] = 5;
            else if(mink[n-1] == 'K')
                ans[n] = 5;
            else
                ans[n] = 0;
        }
        else{
            ans[n] = 1;
            if(mink[n-1] == 'K')
                last = 'K';
        }
    }
    return ans;
}

vector<int> findS(vector<char> mink, int n){
    vector<int> ans(n);
    char last = mink[n-1];
    while(n--){
        if(last == 'K'){
            ans[n] = 5;
            last = mink[n-1];
        }
        else{
            if(n-1 < 0)
                ans[n] = 1;
            else if(mink[n-1] == 'K'){
                ans[n] = 1;
                last = 'K';
            }
            else
                ans[n] = 0;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<char> mink(n);
    for(int i=0; i<n; i++){
        mink[i] = s[i];
    }

    vector<int> ans_l = findL(mink, n);
    vector<int> ans_s = findS(mink, n);
    for(int i=0; i<n; i++){
        cout << ans_l[i];
    }
    cout << '\n';
    for(int i=0; i<n; i++){
        cout << ans_s[i];
    }
}
