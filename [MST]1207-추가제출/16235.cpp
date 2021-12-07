#include <iostream> //표준 입력스트림 사용
#include <vector> //vector
#include <queue> //queue
#include <deque> //deque
#include <tuple> //tuple
#include <algorithm> //sort

using namespace std; //표준 네임스페이스 사용
typedef vector<vector<int>> matrix; //정수형 2차원 벡터 matrix로 정의함
typedef tuple<int, int, int> tp; //tuple<int, int, int>를 tp로 정의함

queue<tp> spring(matrix &land, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) { //땅의 양분 정보, 산 나무, 번식할 나무
    queue<tp> dead_tree; //죽은 나무 저장할 큐
    int size = tree.size(); //살아있는 나무들 수
    while (size--) { //모든 나무 검사
        int age = get<0>(tree.front()); //나이
        int row = get<1>(tree.front()); //행
        int col = get<2>(tree.front()); //열
        tree.pop_front(); //기존 나무 정보 없앰

        if (land[row][col] < age) { //자신의 나이만큼 양분을 먹을 수 없다면
            dead_tree.push({age, row, col}); //죽은 나무에 추가함
            continue; //다음 반복문 계속함
        }
        land[row][col] -= age; //나이만큼 양분 먹음
        tree.emplace_back(age + 1, row, col); //나이 한살 더해서 살아 있는 나무가 더해짐.
        if ((age + 1) % 5 == 0) //나이가 5의 배수라면
            breeding_tree.push({row, col}); //번식할 나무에 더해줌
    }
    return dead_tree; //죽은 나무들을 반환함
}

void summer(queue<tp> &dead_tree, matrix &land) { //죽은 나무, 땅의 양분 정보 벡터
    while (!dead_tree.empty()) { //죽은 모든 나무에 대해
        int age = get<0>(dead_tree.front()); //죽은 나무의 나이
        int row = get<1>(dead_tree.front()); //죽은 나무의 행 위치
        int col = get<2>(dead_tree.front()); //죽은 나무의 열 위치
        dead_tree.pop(); //pop함
        land[row][col] += (age / 2); //나이의 절반이 양분이 됨.
    }
}

void fall(int n, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) { //땅 크기, 산 나무 정보, 번식할 나무 큐
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; //상, 하, 좌, 우, 왼위, 왼아래, 오른위, 오른아래
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1}; //상, 하, 좌, 우, 왼위, 왼아래, 오른위, 오른아래

    while (!breeding_tree.empty()) { //번식할 큐에 있는 모든 나무
        int row = breeding_tree.front().first; //번식할 나무의 행
        int col = breeding_tree.front().second; //번식할 나무의 열
        breeding_tree.pop(); //pop함.

        for (int j = 0; j < 8; j++) { //인접한 8칸에
            int nr = row + dr[j]; //행 위치 정보
            int nc = col + dc[j]; //열 위치 정보
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) //범위 내에 없다면
                continue; //다음 반복문 계속함
            tree.push_front({1, nr, nc}); //새로 생긴 나무
        }
    }
}

void winter(int n, matrix &a, matrix &land) { //땅 크기, 더해줄 양분 양, 땅의 양분
    for (int i = 0; i < n; i++) //n행만큼
        for (int j = 0; j < n; j++) //n열만큼
            land[i][j] += a[i][j]; //양분 더해줌.
}

/**
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * a: 로봇(S2D2)가 겨울에 주는 양분의 양
 * land: 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */

int main() {
    int n, m, k, x, y, z; //땅 크기, 나무 개수, 년 수, 나무 위치, 나무의 나이

    //입력
    cin >> n >> m >> k; //땅, 나무, 년 크기 입력 받음.
    matrix a(n, vector<int>(n, 0)); //로봇이 겨울에 주는 양분의 양
    matrix land(n, vector<int>(n, 5)); //처음 양분 모든 칸에 5
    queue<pair<int, int>> breeding_tree; //번식할 트리
    deque<tp> tree; //나무 정보 tuple 덱
    for (int i = 0; i < n; i++) //n행만큼
        for (int j = 0; j < n; j++) //n열만큼
            cin >> a[i][j]; //양분의 양 입력받음.
    while (m--) { //나무 수만큼
        cin >> x >> y >> z; //위치 정보와 나이 입력받음.
        tree.emplace_back(z, x - 1, y - 1); //(0, 0)부터 시작하도록 구현하기위해 1을 빼준 인덱스에 접근
    }

    //연산
    sort(tree.begin(), tree.end()); //어린 나이 순으로 정렬
    while (k--) { //k년동안
        queue<tp> dead_tree = spring(land, tree, breeding_tree); //봄이 지나고 죽은 나무
        summer(dead_tree, land); //죽은 나무가 양분으로 변함
        fall(n, tree, breeding_tree); //나무가 번식함
        winter(n, a, land); //땅에 양분을 더함.
    }

    //출력
    cout << tree.size(); //살아 있는 나무 수 출력함
}
