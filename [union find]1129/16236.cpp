//
// Created by LG on 2021-11-30.
//
#include <iostream> //표준 입출력 스트림
#include <vector> //vector
#include <queue> //queue
#include <algorithm> //sort

using namespace std; //표준 네임스페이스
const int INF = 401; //최대 이동거리 400
typedef pair<int, int> ci; //pair<int, int> 타입을 ci로 정의

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0}; //행의 상 하 좌 우
    int dc[4] = {0, 0, -1, 1}; //열의 상 하 좌 우

    int min_dist = INF; //최소 이동거리를 최대로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1; //상어가 시작한 위치는 방문 표시함
    q.push(shark); //시작 위치 queue에 push함.
    while (!q.empty()) { //큐가 빌 때까지
        int row = q.front().first; //행 위치 입력
        int col = q.front().second; //열 위치 입력
        int dist = visited[row][col]; //visited에 입력된 1 큰 값으로 초기화함.
        q.pop(); //큐에서 팝 함.

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue; //while문 계속 함.
        for (int i = 0; i < 4; i++) { //상하좌우 4번
            int nr = row + dr[i]; //행 갱신함
            int nc = col + dc[i]; //열 갱신함
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size) //범위 밖이거나 시작 위치이거나 더 크면
                continue; //while문 계속 함.

            visited[nr][nc] = visited[row][col] + 1; //범위 내에 방문할 수 있는 칸이면 현재 거리에 한 칸 더한 거리 입력함.
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //list에 입력함.
                min_dist = visited[nr][nc]; //최단거리 갱신함.
                continue; //while문 계속 함.
            }
            q.push({nr, nc}); //방문할 수 있는데 먹을 수 없는 칸 push함.
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; //갱신되지 않은 min_dist 리턴함.

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬
        if (p1.first != p2.first) //행이 다르면
            return p1.first < p2.first; //행 기준 오름차순
        return p1.second < p2.second; //행이 같다면 열 기준 오름차순
    });
    return {min_dist - 1, list[0]}; //1부터 시작했으므로 -1한 거리와 가까운 칸 중 가장 위, 왼쪽 칸 반환
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0; //시간 입력할 변수, 상어 크기, 먹은 물고기 수
    while (true) { //반복문
        pair<int, ci> result = nextPos(n, size, shark, board); //상어가 이동할 위치 찾음
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; //while문 탈출
        ans += result.first; //최단 거리 더함.
        cnt++; //먹은 물고기 수 늘림.
        if (cnt == size) { //상어 크기 증가
            cnt = 0; //먹은 물고기 초기화하고
            size++; //상어 크기 증가함.
        }

        //상어 이동
        ci pos = result.second; //상어 위치 잠시 저장함.
        board[shark.first][shark.second] = 0; // 아무것도 없는 칸으로 표시함.
        shark = pos; //상어 위치 갱신함.
    }
    return ans; //걸린 초 리턴함.
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n; //공간 크기
    pair<int, int> shark_pos; //상어 위치 변수

    //입력
    cin >> n; //공간 크기 입력
    vector<vector<int>> board(n, vector<int>(n)); //공간 정보 입력 벡터
    for (int i = 0; i < n; i++) { //n열
        for (int j = 0; j < n; j++) { //n행
            cin >> board[i][j]; //물고기 정보 입력 받음
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j); //상어라면 위치 입력 받음
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}
