#include <iostream> //표준 입출력 클래스
#include <vector> // vector
#include <algorithm> // sort

using namespace std; //표준 네임스페이스 사용

vector<int> arr; // 입력받을 배열

//구간의 점수의 최댓값이 score일 때 나뉘는 구간의 개수
int cntSection(int score) {
    //첫번째 구간의 시작
    int cnt = 1;
    int min_value = arr[0], max_value = arr[0];//최솟값, 최댓값이 arr[0]인 상태에서 시작

    for (int i = 1; i < arr.size(); i++) { //구간이 끝날 때까지
        min_value = min(min_value, arr[i]); //현재 구간 안에서 최댓값 갱신
        max_value = max(max_value, arr[i]); //현재 구간 안에서 최솟값 갱신
        if (max_value - min_value > score) { //구간의 점수가 score를 초과한다면 새로운 구간 만들기
            cnt++; //구간의 개수 늘어남
            min_value = arr[i]; //새로운 구간에서 최솟값이 구간의 시작 원소
            max_value = arr[i]; //최댓값이 구간의 시작 원소
        }
    }
    return cnt;//총 나뉜 구간의 개수 반환
}

int lowerSearch(int left, int right, int target) { //구간의 점수의 최댓값의 최솟값을 구하는 함수.
    int ans = 0; //리턴할 값
    while (left <= right) { //left가 right의 오른쪽에 있다면 끝남.
        //구간의 점수의 최댓값이 mid일 때, 몇 개의 구간이 만들어지는가?
        int mid = (left + right) / 2; //중간값
        int section = cntSection(mid); //최댓값이 mid일 때 만들어지는 구간의 수

        if (section <= target) { //만들어지는 구간의 수가 target구간 수보다 작거나 같다면
            ans = mid; //구간의 점수의 최댓값을 mid로 갱신함
            right = mid - 1; //구간의 점수의 최댓값이 더 작은 쪽을 탐색
        } else if (section > target) //만들어지는 구간의 수가 target구간 수보다 많다면
            left = mid + 1; //구간의 점수의 최댓값이 더 큰 쪽을 탐색
    }
    return ans; //최종 구간의 점수의 최댓값 중 가장 작은 값 반환함.
}

/**
 * 배열을 M개 이하의 구간으로 나눈다. 나눈 구간의 점수의 최댓값을 최소로 만든 결과는?
 * -> 구간의 점수의 최댓값이 k라고 할 때, 몇 개의 구간이 필요한가?
 *
 * left (구간 점수의 최댓값의 최솟값) : 배열의 모든 원소가 같다면 구간의 점수는 항상 0이다. 그러므로 구간의 점수의 최댓값도 0이 된다.
 * right (구간 점수의 최댓값의 최댓값) : 구간이 1개라면 그 점수는 가장 큰 값과 가장 작은 값의 차이와 같다.
 */
int main() {
    int n, m; // 배열의 길이와 최대 구간의 개수
    int min_value = 10001, max_value = 0; // 배열 원소 1<=x<=10000이므로 최솟값에 최댓값보다 큰 값, 최댓값에 최솟값보다 작은 값 대입

    //입력
    cin >> n >> m; //n, m입력받음
    arr.assign(n, 0);//배열 길이 n만큼 할당
    for (int i = 0; i < n; i++) {//0부터 n-1까지
        cin >> arr[i];//배열 원소 입력받음
        min_value = min(min_value, arr[i]); //배열의 최솟값 갱신
        max_value = max(max_value, arr[i]); //배열의 최댓값 갱신
    }

    //연산 & 출력
    cout << lowerSearch(0, max_value - min_value, m); //점수의 최솟값은 같은 원소로만 이루어진 구간에서 0, 최댓값은 구간 1개일 때 원소의 최댓값-최솟값
}
