
#include <iostream>
#include <set>

using namespace std;
int main(){
    int lis_num, see_num, cnt=0;
    string s;
    set<string> ans;
    cin >> lis_num >> see_num;

    set<string> listen;

    //듣지 못한 사람 입력
    for(int i=0; i<lis_num; i++){
        cin >> s;
        listen.insert(s);
    }

    //보지 못한 사람 중 듣지도 못한 사람 찾기
    for(int i=0; i<see_num; i++){
        cin >> s;
        if(listen.find(s) != listen.end()){
            ans.insert(s);
            cnt++;
        }
    }

    //출력
    cout << cnt << '\n';
    for(auto iter = ans.begin(); iter != ans.end(); iter++){
        cout << *iter << '\n';
    }

}
