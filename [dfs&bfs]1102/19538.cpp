#include <iostream> //표준 입출력 클래스
#include <vector> //vector
#include <queue> //bfs - queue

using namespace std; //표준 네임스페이스 사용

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {//사람들 정보, 최초 유포자 정보, 사람 수
    vector<int> believer(n + 1, 0); //주변인들이 몇 명 믿는지
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q; //bfs 탐색용 큐

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) { //최초 유포자 수만큼
        ans[init[i]] = 0; //최초 유포자가 믿기 시작한 시간은 0
        q.push(init[i]); //최초 유포자부터 탐색함
    }

    while (!q.empty()) { //큐가 비지 않은 동안
        int v = q.front(); //현재 사람
        int t = ans[v]; //루머 믿은 시간
        q.pop(); //탐색할 노드 큐에서 뺌

        for (int i = 0; i < people[v].size(); i++) { //탐색 중인 사람 주변 노드 수만큼
            int next = people[v][i]; //탐색 노드의 i번째 주변 노드인 사람 검사
            believer[next]++; //next의 주변에서 루머를 믿는 사람 증가
            if (ans[next] != -1) //이미 루머를 믿는 다면
                continue; //다음 주변인으로 넘어감
            if ((people[next].size() + 1) / 2 <= believer[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1; //주변인이 루머를 믿게 된 시간은 현재 노드가 믿은 시간 + 1
                q.push(next); //큐에 탐색할 노드로 추가
            }
        }
    }
    return ans; //결과 리턴
}

/**
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요 (루머를 몇 분 후에 믿는지를 저장하는 배열로 관리)
 */

int main() {
    int n, m, input; // 사람 수, 최초 유포자 수, 입력

    //루머 퍼뜨리는 관계 입력
    cin >> n; //사람 수
    vector<vector<int>> people(n + 1, vector<int>()); //주변인 관계 저장 벡터
    for (int i = 1; i <= n; i++) { // 사람 수만큼
        while (true) { //input이 0이 아닌 동안
            cin >> input; // 주변인 정보 입력받음
            if (!input) // 0이라면
                break; //반복문 종료
            people[i].push_back(input); //i번 사람 주변에 input번 사람 입력
        }
    }

    //최초 유포자 입력
    cin >> m; //최초 유포자 수
    vector<int> init(m, 0); //최초 유포자 저장 벡터
    for (int i = 0; i < m; i++) // 최초 유포자 수만큼
        cin >> init[i]; //유포자 번호 입력 받음

    //연산
    vector<int> ans = bfs(people, init, n); //루머를 믿기 시작한 시간 구함

    //출력
    for (int i = 1; i <= n; i++) //사람 수만큼
        cout << ans[i] << ' '; //루머를 믿기 시작한 시간 출력

    return 0; //종료
}

