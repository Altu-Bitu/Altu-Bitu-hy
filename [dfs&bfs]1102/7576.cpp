//
// Created by BaeSuA on 2021-10-15.
//

#include <iostream> //표준 입출력 스트림
#include <vector> //vector
#include <queue> //bfs - queue

using namespace std; //표준 네임스페이스 사용
typedef pair<int, int> ci; //row, col 저장하기 위한 pair

int bfs(int n, int m, int cnt, vector<vector<int>> &matrix, queue<ci> q) {//행, 열, 토마토 수, 토마토 정보, 익은 토마토 저장 큐
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0}; //행 감소, 행 증가, 0, 0
    int dc[4] = {0, 0, -1, 1}; //0, 0, 열 감소, 열 증가

    int t = 0; //걸린 시간 0일
    while (!q.empty()) { //이웃한 토마토 중 안익은 토마토가 있는 동안
        int cr = q.front().first; //익은 토마토 행 정보 저장
        int cc = q.front().second; //익은 토마토 열 정보 저장
        q.pop(); //저장한 정보 큐에서 뺌
        t = matrix[cr][cc]; //현재 탐색까지 걸린 시간
        cnt--; //익은 토마토 감소
        for (int i = 0; i < 4; i++) { //상, 하, 좌, 우 방향 탐색(인접한 노드 탐색)
            int nr = cr + dr[i]; //방문하려는 노드
            int nc = cc + dc[i]; //방문하려는 노드
            if (nr > 0 && nr <= n && nc > 0 && nc <= m && matrix[nr][nc] == 0) { //노드가 존재(행렬 범위 안에 있음), 익지 않은 토마토라면
                matrix[nr][nc] = matrix[cr][cc] + 1; //시간 증가값을 토마토 행렬에 저장
                q.push(ci(nr, nc)); //익은 토마토 정보를 q에 넣음
            }
        }
    }

    if (!cnt) //모든 토마토가 익었다면
        return t - 1; //첫번째 토마토가 익는 데 걸리는 시간 0일이었으므로
    return -1;//토마토가 모두 익지 못한다면
}

int main() {
    queue<ci> q; //bfs 탐색을 위한 토마토 위치 저장 큐
    int n, m; //행의 수 n, 열의 수 m

    //입력
    cin >> m >> n; //열, 행 입력받음
    int cnt = n * m; //전체 토마토 개수
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0)); //토마토 정보 저장
    for (int i = 1; i <= n; i++) { //행의 수만큼
        for (int j = 1; j <= m; j++) { //열의 수만큼
            cin >> matrix[i][j]; //토마토 정보 입력받음
            if (matrix[i][j] == 1) //익은 토마토 바로 삽입 (시작 노드)
                q.push(ci(i, j)); //큐에 익은 토마토 행열 정보 삽입ㅇ
            else if (matrix[i][j] == -1) //토마토가 없다면
                cnt--; //익어야되는 토마토 개수 감소
        }
    }

    //탐색 & 출력
    cout << bfs(n, m, cnt, matrix, q); // 결과 출력

    return 0; //종료
}
