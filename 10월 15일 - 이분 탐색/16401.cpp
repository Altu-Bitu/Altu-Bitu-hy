#include <iostream> //표준 입출력 클래스
#include <vector> // vector
#include <algorithm> // sort

using namespace std; //표준 네임스페이스 사용

int childNum(vector<int> &snacks, int len) {//각 길이마다 나누어 줄 수 있는 인원 구함
    int cnt = 0; //몇 명에게 나누어주는지
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break; //len만큼씩 나누어줄 때 len보다 작아지면 못 나눠줌.
        cnt += (snacks[i] / len); //막대 길이를 나눠줄 길이로 나눈 몫씩 더해감.
    }

    return cnt;//총 나눠줄 수 있는 인원 리턴함.
}

int upperSearch(vector<int> &snacks, int left, int right, int target) {//나눠줄 수 있는 길이 중 가장 긴 길이 구함.
    int ans = 0;
    while (left <= right) { // left가 right보다 크면 끝남.
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(snacks, mid); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1;//왼쪽 경계를 중간값+1로 옮김
            ans = mid;//정답 mid로 갱신함.
        } else { //더 많은 아이들에게 나누어줘야 한다면 막대 길이 줄여야함
            right = mid - 1; //오른쪽 경계를 중간값-1로 옮김.
        }
    }

    return ans; //나눠줄 수 있는 길이 중 가장 큰 값 반환함.
}

/**
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0; //나눠줘야할 아이들 수, 막대과자 수, 가장 작은 길이 left 1, 가장 긴 길이 저장할 변수 right

    //입력
    cin >> m >> n; //아이들 수와 과자 수
    vector<int> snacks(n, 0);//과자 길이 정보 입력할 벡터
    for (int i = 0; i < n; i++)//n만큼
        cin >> snacks[i];//과자 길이 입력받음.

    //연산
    sort(snacks.begin(), snacks.end());//과자 길이 오름차순으로 정렬
    right = snacks[n - 1];//가장 긴 과자 길이 입력

    //연산 & 출력
    cout << upperSearch(snacks, left, right, m);//나눠줄 수 있는 가장 긴 길이 찾기

    return 0;//0 반환함
}
