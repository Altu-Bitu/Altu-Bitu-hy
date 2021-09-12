
#include <iostream>
#include <map>

using namespace std;
int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n, ans=1;
        string name, type;

        cin >> n;
        map<string, int> wear;

        //입력
        for(int i=0; i<n; i++){
            cin >> name >> type;
            wear[type]++;
        }

        //옷을 조합하는 가짓수
        for(auto iter = wear.begin(); iter != wear.end(); iter++){
            ans *= (*iter).second+1;
        }

        //아무것도 입지 않는 경우 빼고 출력
        cout << ans-1 << '\n';
    }
}
