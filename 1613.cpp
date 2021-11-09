#include <iostream> //표준 입력스트림 사용
#include <vector> //vector

using namespace std; //표준 네임스페이스 사용

void floydWarshall(int n, vector<vector<bool>> &graph) { //사건 수 n, 알고 있는 전후관계 그래프
    for (int k = 1; k <= n; k++) { //모든 k에 대해서
        for (int i = 1; i <= n; i++) { //어떤 i와
            for (int j = 1; j <= n; j++) { //어떤 j에 대해서
                if (graph[i][k] && graph[k][j]) //i->k, k->j 전후관계 있는 경우
                    graph[i][j] = true; //i와 j는 전후관계에 있음
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);//입출력 속도 개선
    cin.tie(NULL); //입출력 속도 개선

    int n, k, s, a, b; //사건 수, 전후 관계 수, 알고 싶은 사건 수, 사건 a와 b

    //입력
    cin >> n >> k; //사건 수, 전후 관계 수
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false)); // false이면 전후관계 아님, true이면 전후관계
    while (k--) { // 전후 관계 수만큼
        cin >> a >> b; //a 와 b 입력받음
        graph[a][b] = true; //전후관계 -> 단방향 그래프
    }

    //연산
    floydWarshall(n, graph); //전후관계 그래프 연산

    //입력 & 출력
    cin >> s; //사건 수 입력
    while (s--) { //사건 수만큼
        cin >> a >> b; //확인할 a와 b입력받음
        if (graph[a][b]) //graph[a][b]가 true라면
            cout << "-1"; //a 후에 b가 발생함
        else if (graph[b][a]) //graph[b][a]가 true라면
            cout << "1"; //b 후에 a가 발생함
        else
            cout << "0"; // 둘 다 false라면 전후관계 알 수 없음
        cout << '\n'; // 출력 형식
    }
    return 0; //종료
}
