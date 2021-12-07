#include <iostream> //표준 입력스트림 사용
#include <vector> //vector
#include <map> //map

using namespace std; //표준 네임스페이스 사용
typedef pair<int, int> ci; //pair<int, int>형을 ci로 정의함

map<int, ci>::iterator delCandidate(map<int, ci> &candidate) { //후보자 정보
    auto del = candidate.begin(); //처음 후보를 삭제한다 가정
    int cnt = candidate.begin()->second.first; //처음 후보의 추천 횟수
    int t = candidate.begin()->second.second; //처음 후보의 게시 시간
    for (auto iter = ++candidate.begin(); iter != candidate.end(); iter++) { //게시판 두 번째 후보자부터 마지막 후보자에 대해
        int cur_cnt = iter->second.first; //비교할 추천수 대입
        int cur_t = iter->second.second; //비교할 게시 시간 대앱
        if (cur_cnt < cnt) { //추천 횟수가 가장 작은 후보 찾기
            cnt = cur_cnt; //최소 추천수 갱신
            t = cur_t; //게시 시간 갱신
            del = iter; //삭제할 후보 갱신
        } else if (cur_cnt == cnt && cur_t < t) { //추천 횟수가 가장 작은 후보가 여러명이라면, 게시 시간이 오래된 후보 찾기
            t = cur_t; //게시 시간 갱신
            del = iter; //삭제할 후보 갱신
        }
    }
    return del; //삭제할 후보 가리키는 iterator 리턴함
}

/**
 * 1. 비어있는 사진틀이 없는 경우, 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생을 삭제
 * 2. 후보 학생을 바로 찾기 위해 본 풀이는 map 컨테이너를 사용해 구현
 *
 * !주의! 게시 시간 정보 저장 시, 후보로 올라간 가장 첫 시간을 저장. 이미 후보에 있는데 게시 시간이 갱신되지 않도록 주의.
 */

int main() {
    int n, m, input; //사진틀 수, 총 투표수, 학생 번호 받을 변수

    //입력 & 연산
    cin >> n >> m; //사진틀, 총 투표수 입력받음
    map<int, ci> candidate; //first: 후보 학생, second: {추천 횟수, 게시 시간}
    for (int i = 0; i < m; i++) { //총 투표수만큼
        cin >> input; //학생 번호 입력받음
        if (candidate.size() == n && candidate.find(input) == candidate.end()) //비어있는 사진틀이 없는 경우
            candidate.erase(delCandidate(candidate)); //조건에 따라 후보 지움

        if (candidate.find(input) == candidate.end()) //첫 게시라면
            candidate[input].second = i; //게시 시간 입력함.
        candidate[input].first++; //추천 횟수 증가
    }

    //출력
    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) //게시된 모든 후보자들의
        cout << iter->first << ' '; //득표수 출력함
}
