#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<char> gl;
string s;
vector<string> ans;
bool check[10];
int name[10];

void backtracking(int cnt, int prev, char c){
    if(cnt == n+1){
        s = "";
        for(int i=0; i<=n; i++){
            s += to_string(name[i]);
        }
        ans.push_back(s);
        return;
    }

    if(c == '<'){
        for(int i=prev+1; i<10; i++){
            if(!check[i]){
                check[i] = true;
                name[cnt] = i;
                backtracking(cnt+1, i, gl[cnt]);
                check[i] = false;
            }
        }
    }
    else if(c == '>'){
        for(int i=0; i<prev; i++){
            if(!check[i]){
                check[i] = true;
                name[cnt] = i;
                backtracking(cnt+1, i, gl[cnt]);
                check[i] = false;
            }
        }
    }
}

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        char ch;
        cin >> ch;
        gl.push_back(ch);
    }

    backtracking(0, -1, '<');
    sort(ans.begin(), ans.end());

    cout << ans.back() << '\n' << ans.front();

}
