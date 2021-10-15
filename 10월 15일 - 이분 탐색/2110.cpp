#include <iostream> // 표준 입출력 클래스
#include <vector> // vector
#include <algorithm> // sort

using namespace std; // 표준 네임스페이스 사용

vector<int> house; // 집 위치 벡터

//가장 인접한 두 공유기 사이의 거리가 dist이도록 공유기를 설치했을 때, 설치된 공유기 숫자
int router(int dist) {
    //첫번째 집에 무조건 공유기 설치
    int cnt = 1;
    int pos = house[0]; //마지막으로 설치된 공유기의 위치

    for (int i = 1; i < house.size(); i++) {//각 집마다 공유기 설치 가능 여부 확인
        if (house[i] - pos < dist) //가장 가까운 집과의 거리가 dist 이상이어야 설치 가능
            continue; //거리가 가깝다면 다음 집을 확인함
        //i번째 집에 공유기 설치
        cnt++; //총 공유기 개수 늘어남
        pos = house[i]; //마지막 공유기 위치 갱신
    }
    return cnt; //설치된 공유기 수
}

//가능한 최대 거리 중 가장 큰 값(=upper bound)
int upperSearch(int left, int right, int target) {//target을 초과한 값이 처음으로 나타나는 위치-1 찾기
    int ans = 0;//리턴할 값
    while (left <= right) {//left가 right의 오른쪽에 있으면 끝남
        //가장 인접한 두 공유기 사이의 거리가 mid일 때, 공유기를 최대 몇 개 설치할 수 있는가?
        int mid = (left + right) / 2; //중간값
        int installed = router(mid); //mid에 설치된 공유기의 개수

        if (installed < target) //mid의 거리로는 target만큼의 공유기를 설치할 수 없음 -> 거리를 줄여야
            right = mid - 1; //오른쪽 경계를 mid-1로 옮김
        else if (installed >= target) { //mid의 거리로는 target만큼의 공유기를 설치할 수 있음 -> 거리를 늘려보자
            ans = mid; //현재의 mid값 저장. 최종 갱신되는 값은 upper bound
            left = mid + 1; //왼쪽 경계를 mid+1로 옮김
        }
    }
    return ans; // target보다 큰 값이 처음으로 나타나는 위치를 찾기 직전의 mid값 = 가능한 최대 거리 중 가장 큰 값
}

int main() {
    int n, c; // 집의 개수 n, 공유기 개수 c

    //입력
    cin >> n >> c;
    house.assign(n, 0); //house 벡터에 n만큼 할당
    for (int i = 0; i < n; i++) //n만큼
        cin >> house[i]; //집의 위치를 입력받음

    //연산
    sort(house.begin(), house.end()); //오름차순 정렬함

    //연산 & 출력
    //공유기 사이의 최단 거리 (left) : 1
    //공유기 사이의 최장 거리 (right) : 가장 멀리 있는 두 집 사이의 거리
    cout << upperSearch(1, house[n - 1] - house[0], c);
}
