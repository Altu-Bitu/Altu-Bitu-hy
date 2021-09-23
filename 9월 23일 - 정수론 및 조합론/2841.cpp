#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n, p;
    cin >> n >> p;

    stack<int> line[7];

    int ans = 0;
    for(int i=0; i<n; i++){
        int k, v;
        cin >> k >> v;
        //줄에 눌린 프렛이 없을 때
        if(line[k].empty()){
            line[k].push(v);
            ans++;
        }
        //더 낮은 프렛이 눌려있을 때
        else if(v > line[k].top()){
            line[k].push(v);
            ans++;
            continue;
        }
        //더 높은 프렛이 눌려있을 때
        else if(v < line[k].top()){
            while(!line[k].empty() && v < line[k].top()){
                line[k].pop();
                ans++;
            }
            if(line[k].empty() || line[k].top() != v) {
                line[k].push(v);
                ans++;
            }
        }
    }
    cout << ans;
}

