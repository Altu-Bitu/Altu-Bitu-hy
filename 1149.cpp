
#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b, int c){
    return b > a ? c > a ? a : c : c > b ? b : c;
}

int find(vector<vector<int>> dp, vector<vector<int>> cost, int n){

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + cost[i][2];
    }

    return min(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
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
