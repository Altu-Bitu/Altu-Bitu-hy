
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
vector<int> temp(7);
set<vector<int>> out;

void backtracking(int cnt, vector<int> nums){
    if(cnt == m){
        out.insert(temp);
        return;
    }

    for(int i=0; i<n; i++){
        temp[cnt] = nums[i];
        backtracking(cnt+1, nums);
    }
}

int main(){

    cin >> n >> m;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    backtracking(0, nums);

    for(auto it=out.begin(); it != out.end(); it++){
        vector<int> t = *it;
        for(int j=0; j<m; j++){
            cout << t[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
