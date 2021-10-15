#include <iostream> //표준 입출력 클래스
#include <vector> // vector
#include <algorithm> // sort

using namespace std; //표준 네임스페이스 사용

vector<int> arr; // 입력받을 배열

//이분 탐색
bool binarySearch(int left, int right, int target) {//왼쪽, 오른쪽 경계와 찾으려는 값 target
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값
        if (arr[mid] == target) //target을 찾음
            return true; // true 반환함
        if (arr[mid] > target) //중간값이 target보다 크다면 target은 왼쪽에 있음
            right = mid - 1; // 오른쪽 경계가 중간값 -1에 위치
        if (arr[mid] < target) //중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid + 1; // 왼쪽 경계가 중간값 +1에 위치
    }
    return false; //target을 찾지 못함
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(NULL); // 입력 속도 향상

    int n, m, input; // n개의 정수가 주어졌을 때 m개의 input 이 그 중에 존재하는지 찾음.

    //입력
    cin >> n; //n개의 정수 입력받음
    arr.assign(n, 0); // vector arr에 n만큼 할당함.
    for (int i = 0; i < n; i++) // n번동안
        cin >> arr[i]; // arr[i]를 입력받음.

    //연산
    sort(arr.begin(), arr.end()); //이분 탐색을 하기 위해선 반드시 정렬을 해야함

    //입력
    cin >> m; //찾을 정수의 개수
    while (m--) { // m이 0이 될 때까지
        cin >> input; // 찾을 정수 입력받음

        //연산 & 출력
        cout << binarySearch(0, n - 1, input) << '\n'; // input을 찾아서 결과를 출력함.
        //cout << binary_search(arr.begin(), arr.end(), input) << '\n';
    }
}
