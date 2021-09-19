
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<>> least;
    priority_queue<int> temp;

    for(int i=0; i<n; i++){
        int people, limit;
        cin >> people >> limit;
        //신청한 사람이 수강인원보다 작다면
        if(people < limit){
            least.push(1);
            for(int j=0; j<people; j++){
                int t;
                cin >> t;
            }
        }
        else{
            temp = priority_queue<int>();
            for(int j=0; j<people; j++){
                int t;
                cin >> t;
                temp.push(t);
            }
            //최소로 배당해야할 마일리지 찾고 입력
            for(int j=0; j<limit-1; j++){
                temp.pop();
            }
            least.push(temp.top());
        }
    }

    int answer=0, total=0;
    while(total <= m && !least.empty()){
        total += least.top();
        least.pop();
        if(total <= m)
            answer ++;
    }

    cout << answer;
}
