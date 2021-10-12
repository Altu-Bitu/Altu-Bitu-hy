//
// Created by LG on 2021-10-08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score, cur;

void run(vector<int> &ground, int i){
    for (int k = 0; k < 9; k++) {
        if (ground[k] > 0) {
            ground[k] += i;
            if (ground[k] > 3) {
                ground[k] = 0;
                score++;
            }
        }
    }
    ground[cur] += i;
}

int play(vector<vector<int>> hit, int inning) {

    int ans = 0;
    vector<int> order = {1, 2, 3, 4, 5, 6, 7, 8};
    do{
        order.insert(order.begin()+3, 0);
        //https://hsdevelopment.tistory.com/164

        //1~9번 선수 순으로 결과를 넣은 hit 벡터
        //이닝마다 타순대로 결과를 넣은 hit_order 스택
        score = 0;
        cur = 0; // 0~8번 타자 중 현재 몇 번째 타자인지
        for (int i = 0; i < inning; i++) {
            int out = 0;
            vector<int> ground(9, 0); // 선수들이 몇 루에 있는지. 인덱스는 타순.

            while (true) { // 한 이닝에서 3아웃이 나올 동안
                if(cur==9)
                    cur = 0;
                int t = hit[i][order[cur]]; // 현재 타자가 칠 공의 유형
                if (t == 0) {
                    out++;
                    if (out == 3) {
                        cur++;
                        break;
                    }
                }
                else if (t == 4) {
                    score++;// 타자도 홈을 통과함.
                    for (int k = 0; k < 9; k++) {
                        if (ground[k] > 0) {
                            ground[k] = 0;
                            score++;
                        }
                    }
                }
                else
                    run(ground, t);

                cur++; // 0번 타자부터 시작

            }
        }
        ans = max(ans, score);
        order.erase(order.begin()+3);
    }while(next_permutation(order.begin(), order.end()));
    //https://notepad96.tistory.com/entry/C-%EC%88%9C%EC%97%B4Permutation-nextpermutation

    return ans;
}

int main(){
    int n; //이닝 수
    cin >> n;
    vector<vector<int>> hit(n, vector<int>(9));
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
            cin >> hit[i][j];
        }
    }

    cout << play(hit, n);

}
