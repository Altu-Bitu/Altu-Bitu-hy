#include <iostream>//표준 입출력 클래스
#include <map>//맵

using namespace std;//표준 네임스페이스 사용

/**
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */
int main() {
    ios::sync_with_stdio(false);//입출력 속도 향상
    cin.tie(NULL);//입력 속도 향상

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power;//칭호의 종류 개수와 주어진 전투력의 개수, 입력받을 전투력 변수
    string name;//입력받을 칭호 변수

    //입력
    cin >> n >> m; //칭호의 가짓수와 분류할 전투력의 수
    while (n--) {//n이 0이 될 때까지
        cin >> name >> power;//칭호와 경계 전투력 입력받음
        if (title[power].empty()) //여러 칭호가 가능하다면 먼저 입력된 칭호로 결정되므로, 이미 입력받은 전투력이 아닐 경우에만
            title[power] = name; //맵에 해당 전투력에 대한 칭호를 넣음.
    }

    //출력
    while (m--) { //m이 0이 될 때까지
        cin >> power; //분류할 전투력 입력받음
        cout << title.lower_bound(power)->second << '\n'; //전투력보다 크거나 같은 값이 처음으로 나오는 인덱스의 칭호를 출력함
    }
}
