
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<pair<int, int>> v, int n) {

    int count = 1;
    int temp = v[0].second;
    for(int i=1; i<n; i++){
        if(v[i].second < temp) {
            count++;
            temp = v[i].second;
        }
    }

    return count;

}

int main(){
    int t;
    cin >> t;
    
    //입력, 정렬
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for(int j=0; j<n; j++){
            cin >> v[j].first >> v[j].second;
        }

        sort(v.begin(), v.end());

        cout << solution(v, n) << '\n';
    }
    
}
