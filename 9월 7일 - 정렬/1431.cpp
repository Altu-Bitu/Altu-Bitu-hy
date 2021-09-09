#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string s){
    int sum = 0;

    for (int j = 0; j < s.length(); j++) {
        if (s[j] >= '0' && s[j] <= '9')
            sum += s[j]-'0';
    }
    return sum;
}

bool cmp(const string &i1, const string &i2){
    if(i1.length() != i2.length())
        return i1.length() < i2.length();
    if(sum(i1) != sum(i2))
        return sum(i1) < sum(i2);
    return i1 < i2;
}

int main() {
    int n;
    cin >> n;
    string num[n];

    //입력
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    //정렬
    sort(num, num+n, cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << num[i] << '\n';
    }
}
