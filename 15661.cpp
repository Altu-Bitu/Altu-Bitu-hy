
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int permutation(vector<bool> num, int n, vector<vector<int>> stat){
    int ans = 2000;

    for(int i=0; i<n/2; i++){
        num[i] = true;
    }

    do{
        int l_total = 0, s_total = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(num[i] && num[j])
                    l_total += stat[i][j];
                else if(!num[i] && !num[j])
                    s_total += stat[i][j];
            }
        }
        ans = min(ans, abs(l_total-s_total));
    }while(prev_permutation(num.begin(), num.end()));

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> stat(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> stat[i][j];
        }
    }

    vector<bool> num(n, false);

    cout << permutation(num, n, stat);

    return 0;
}
