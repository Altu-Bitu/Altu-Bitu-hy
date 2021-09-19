#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(int &a, int &b){
        if(abs(a) != abs(b))
            return abs(a) > abs(b);
        return a > b;
    }
};

int main(){
    int n;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(t == 0){
            if(!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << '0' << '\n';
        }
        else
            pq.push(t);
    }
}

