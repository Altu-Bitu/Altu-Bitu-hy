
#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c){
    return b > a ? c > a ? a : c : c > b ? b : c;
}

int find(vector<vector<int>> dp, vector<vector<int>> cost, int n){

    int ans [3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(j==i)
                dp[0][j] = cost[0][j];
            else
                dp[0][j] = 100001;
        }

        for(int j=1; j<n; j++){
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + cost[j][0];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + cost[j][1];
            dp[j][2] = min(dp[j-1][1], dp[j-1][0]) + cost[j][2];
        }

        if(i==0)
            ans[i] = min(dp[n-1][1], dp[n-1][2]);
        else if(i==1)
            ans[i] = min(dp[n-1][0], dp[n-1][2]);
        else
            ans[i] = min(dp[n-1][0], dp[n-1][1]);
    }

    return min(ans[0], ans[1], ans[2]);
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(3, 0));
    for(int i=0; i<n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    cout << find(dp, cost, n);

}
