
#include <iostream>
#include <vector>

using namespace std;

struct info{
    int d, m;
};

int find(vector<info> counsel, int n){
    vector<int> dp(n+1);

    //마지막 날 하루 걸리는 상담일때만 상담함.
    if(counsel[n].d == 1)
        dp[n] = counsel[n].m;
    else
        dp[n] = 0;

    for(int i=n-1; i>0; i--){
        if(i+counsel[i].d < n+2) // 상담을 할 수 있다면
            if(i+counsel[i].d < n+1) // 상담 마지막 날 다음 날 dp가 있으면
                dp[i] = max(dp[i+counsel[i].d]+counsel[i].m, dp[i+1]);
            else // 상담 마지막 날 다음 날 dp가 없으면
                dp[i] = max(counsel[i].m, dp[i+1]);
        else
            dp[i] = dp[i+1];
    }

    return dp[1];
}

int main(){
    int n;
    cin >> n;

    //입력
    vector<info> counsel(n+1);
    for(int i=1; i<=n; i++){
        cin >> counsel[i].d >> counsel[i].m;
    }

    cout << find(counsel, n);

}
