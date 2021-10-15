#include <iostream> // 표준 입출력 클래스
#include <vector> // vector
#include <algorithm> // sort

using namespace std; // 표준 네임스페이스 사용

vector<int> arr; //카드 정보를 입력받을 벡터

//lower bound
int lowerBound(int left, int right, int target) {//값이 target 이상이면서 인덱스가 가장 작은 값의 인덱스를 반환
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값
        //중간값이 target보다 크다면 target은 왼쪽에 있음
        //중간값이 target과 같다면 왼쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] >= target)//중간값이 target보다 크거나 같다면
            right = mid - 1;//오른쪽 경계가 중간값 -1에 위치
        if (arr[mid] < target) //중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid + 1; //왼쪽 경게를 중간값+1에 위치
    }
    /**
     * right + 1을 리턴하는 이유
     * right가 움직일 때는 arr[mid]가 target 이상일 때
     * 값이 target 이상이면서, 인덱스가 가장 작은 mid값이 lower bound!
     * right는 mid - 1이므로 right + 1은 lower bound
     */
    return right + 1; // target 이상의 수가 처음으로 나오는 위치
}

//upper bound
int upperBound(int left, int right, int target) { // 값이 target 이상이면서 인덱스가 가장 큰 값의 인덱스를 반환
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값
        if (arr[mid] > target) //중간값이 target보다 크다면 target은 왼쪽에 있음
            right = mid - 1;//오른쪽 경계가 중간값 -1에 위치
        //중간값이 target보다 작다면 target은 오른쪽에 있음
        //중간값이 target과 같다면 오른쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] <= target) //target이 중간값보다 크거나 같다면
            left = mid + 1;//왼쪽 경계를 중간값+1에 위치
    }
    /**
     * right + 1을 리턴하는 이유
     * break 직전 left와 right는 같은 곳을 가리킴
     * 이 상태에서 right(mid)가 가리키는 값은 target 이하기 때문에 left 포인터가 이동하고 break
     * 이 때의 left값은 target을 처음으로 초과하는 upper bound이며 직전에 left와 right의 위치가 같았으므로 right + 1 == left
     */
    return right + 1; // target을 초과하는 수가 처음으로 나오는 위치
}

int main() {
    ios::sync_with_stdio(false);//입출력 속도 향상
    cin.tie(NULL);//입력 속도 향상

    int n, m, input; //카드의 개수와 찾을 정수의 개수 n, m, 찾을 값을 저장할 input

    //입력
    cin >> n; //카드의 개수 n
    arr.assign(n, 0); // 벡터에 n만큼을 할당함
    for (int i = 0; i < n; i++) //i=0부터 n까지
        cin >> arr[i]; // 벡터에 입력 받음.

    //연산
    sort(arr.begin(), arr.end()); //이분 탐색을 하기 위해선 반드시 정렬을 해야함

    //연산
    cin >> m; //찾을 정수의 개수 m
    while (m--) { //m이 0이 될 때까지
        cin >> input; //찾을 정수 입력 받음

        //연산 & 출력
        cout << upperBound(0, n - 1, input) - lowerBound(0, n - 1, input) << ' '; // 찾을 정수의 최대 인덱스-최소 인덱스가 개수가 됨.
        //cout << upper_bound(arr.begin(), arr.end(), input) - lower_bound(arr.begin(), arr.end(), input) << ' ';
    }
}