//
// Created by LG on 2021-09-27.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int score(int n, map<string, int> answer, vector<string> hyunwoo){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(answer[hyunwoo[i]] < answer[hyunwoo[j]]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    map<string, int> answer;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        answer.insert(pair<string, int>(s, i));
    }

    vector<string> hyunwoo(n);
    for(int i=0; i<n; i++){
        cin >> hyunwoo[i];
    }

    cout << score(n, answer, hyunwoo) << "/" << n*(n-1)/2;
}