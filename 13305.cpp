#include <iostream>
#include <vector>

using namespace std;

long long solution(long long n, vector<long long> dist, vector<long long> price){
    long long answer = 0;

    long long low = price[0];
    for(int i=0; i<n-1; i++){
        if(price[i] < low)
            low = price[i];
        answer += low*dist[i];
    }
    return answer;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> dist(n - 1);
    vector<long long> price(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    cout << solution(n, dist, price);
}

