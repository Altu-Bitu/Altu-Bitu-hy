
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &i1, const pair<string, int> &i2){
    if(i1.second != i2.second)
        return i1.second > i2.second;
    if(i1.first.size() != i2.first.size())
        return i1.first.size() > i2.first.size();
    return i1.first < i2.first;
}
int main(){

    int n, len;
    cin >> n >> len;

    //맵에 단어와 횟수를 입력
    map<string, int> word;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s.length() >= len)
            word[s]++;
    }

    //벡터에 맵 입력
    vector<pair<string, int>> answer(word.begin(), word.end());
    //정렬
    sort(answer.begin(), answer.end(), cmp);

    //출력
    for(int i=0; i<answer.size(); i++){
        cout << answer[i].first << '\n';
    }

}
