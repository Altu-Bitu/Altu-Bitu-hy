#include <iostream> //표준 입출력 스트림 사용
#include <vector> //vector

using namespace std; //표준 네임스페이스 사용

int n, m, ans = 65; //세로, 가로, 사각지대 최대 64이므로 답을 65로 초기화
vector<vector<int>> board; //방 정보 입력받는 벡터 선언

//cctv 범위 표시
void ray(int row, int col, int dir) { //행, 열, 상하좌우 중 한 방향
    int dr[4] = {-1, 0, 1, 0}; //상, 우, 하, 좌
    int dc[4] = {0, 1, 0, -1}; //시계방향

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //dir 방향으로 뻗어나가며 cctv 표시
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col] = 7; //범위 내에 있음을 7로 표시
        row += dr[dir]; //행을 방향을 향해 이동함
        col += dc[dir]; //열을 방향을 향해 이동함
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) { //cctv 종류, 위치, cctv 설치하는 방향
    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir); //dir쪽을 향해 cctv 범위 표시함
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4); //(dir+2)%4쪽을 향해 cctv 범위 표시함
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4); //(dir+1)%4쪽을 향해 cctv 범위 표시함
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4); //(dir+3)%4쪽을 향해 cctv 범위 표시함
}

//사각지대 계산
int blindSpot() {
    int cnt = 0; //사각지대 수 초기화
    for (int i = 0; i < n; i++) { //행만큼
        for (int j = 0; j < m; j++) { //열만큼
            if (!board[i][j]) //0이라면
                cnt++; //cnt 증가시킴
        }
    }
    return cnt; //cnt 반환
}

void backtracking(int idx) { //백트래킹 함수. 0~n*m-1 현재 칸 수
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return; //종료
    }

    int row = idx / m; //idx번째를 m으로 나눈 몫이 그 칸의 행
    int col = idx % m; //idx번째를 m으로 나눈 나머지가 그 칸의 행
    int cur = board[row][col]; //현재 칸 cctv 정보 cur에 저장
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳
        return backtracking(idx + 1); //다음 칸 백트래킹 함수 호출

    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치
        install(cur, row, col, i); //cctv cur종류일 때 i방향에 대해 설치
        backtracking(idx + 1); //다음 칸 백트래킹 함수 호출
        board = save; //원래 상태로 돌아옴.

        //2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0)) //불필요한 탐색하지 않도록
            break; //break함
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m; //세로, 가로 크기 입력
    board.assign(n, vector<int>(m)); //n*m 크기 방 크기 벡터에 할당
    for (int i = 0; i < n; i++) { //세로 n
        for (int j = 0; j < m; j++) //가로 n만큼
            cin >> board[i][j]; //cctv 정보 입력받음
    }

    //연산
    backtracking(0);

    //출력
    cout << ans;
}
