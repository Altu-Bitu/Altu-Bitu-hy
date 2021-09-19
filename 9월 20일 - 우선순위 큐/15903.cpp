#include <iostream>
#include <queue>

using namespace std;

int  main(){
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<>> q;

    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        q.push(t);
    }

    for(int i=0; i<m; i++){
        long long a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a+b);
        q.push(a+b);
    }

    long long answer;
    for(int i=0; i<n; i++){
        answer += q.top();
        q.pop();
    }

    cout << answer;
}
