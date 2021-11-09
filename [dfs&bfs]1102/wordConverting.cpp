#include <iostream> //표준 입출력 스트림
#include <string> //string
#include <vector> //vector
#include <map> // map
#include <queue> //bfs - queue

using namespace std; //표준 네임스페이스 사용

//str1과 str2가 서로 변환 가능한지 확인
bool convertible(string str1, string str2) { // 비교할 두 문자열
    int diff = 0; // 다른 문자 수
    for (int i = 0; i < str1.size(); i++) { //첫~끝 문자열까지
        if (str1[i] != str2[i]) // 문자가 다르다면
            diff++; // 다른 문자 수 증가
    }
    return diff == 1; //다른 문자수가 1개일 때 true 리턴
}

//각 단어들 사이의 연결 관계 설정
map<string, vector<string>> makeGraph(vector<string> words, int size){ //단어 집합과 단어 집합 속 단어 수+1
    map<string, vector<string>> graph; // 각 단어와 연결 관계에 있는 단어들의 집합 맵

    for (int i = 0; i < size; i++) { //단어 집합 수만큼
        vector<string> list; //연결된 단어를 저장할 벡터
        for (int j = 0; j < size; j++) { //단어 집합 수만큼
            if (convertible(words[i], words[j])) //서로 변환 가능한 단어라면 연결 관계 성립
                list.push_back(words[j]); //연결 관계라면 매핑되는 벡터에 저장
        }
        graph[words[i]] = list; //i번째 단어의 value 저장
    }
    return graph; //연결된 그래프 리턴
}

//bfs로 begin에서 target으로 변환하는 가장 짧은 변환 과정 찾기
int bfs(map<string, vector<string>> graph, string begin, string target) { //연결관계 그래프, 시작 단어, 목표 단어
    map<string, int> dist; //변환 단계 수
    queue<string> q; //

    dist[begin] = 1; //초기값이 0이므로 1로 초기화
    q.push(begin); //시작 단어부터 시작

    while (!q.empty()) { //큐가 비지 않은 동안
        string cur = q.front(); //현재 상태인 단어 cur에 입력
        q.pop(); //현재 단어 큐에서 뺌

        if (cur == target) //target으로 변환 성공
            return dist[cur] - 1; //초기값 1이었으므로 -1

        vector<string> list = graph[cur]; //연결 관계에 있는 단어들 list에 대입
        for (int i = 0; i < list.size(); i++) { //list 크기만큼
            string next_node = list[i]; //cur에서 변환 가능한 단어
            if (!dist[next_node]) { //아직 확인하지 않은 단어라면
                dist[next_node] = dist[cur] + 1; //현재 단어에 한 단계 더해서 대입
                q.push(next_node); //다음 확인할 단어로 push함.
            }
        }
    }
    return 0; //target으로 변환 실패
}

int solution(string begin, string target, vector<string> words) { //시작 단어, 종료 단어, 단어들 집합 매개변수
    words.push_back(begin); //시작 단어를 words 배열 안의 단어로 변환해야 하기 때문에 연결 관계 탐색에 넣어줌
    return bfs(makeGraph(words, words.size()), begin, target);
}

/**
 * begin에서 target으로 변환하는 가장 '짧은' 변환 과정
 * -> 최단거리 문제이므로 bfs
 *
 * 각 단어 사이 변환 가능 여부를 그래프의 연결 관계로 표현할 수 있음
 *
 * hit과 hot은 연결됨
 * hit과 cog는 연결되지 않음
 *
 * 연결 관계
 * hit | hot
 * hot | dot lot hit
 * dot | hot dog lot
 * dog | dot log cog
 * lot | hot dot log
 * log | dog lot cog
 * cog | dog log
 */
int main() {
    string begin = "hit"; //시작 단어
    string target = "cog"; //목표 단어
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"}; //거쳐갈 수 있는 단어 집합

    cout << solution(begin, target, words); //가장 적게 거칠 수 있는 단계 출력
}

