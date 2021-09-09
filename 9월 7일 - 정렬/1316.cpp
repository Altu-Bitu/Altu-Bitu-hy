#include <iostream>
using namespace std;

bool checker(string s){
    bool check [26] = {};
    int len = s.length();

    for(int j=0; j<len; j++){
        char ch = s[j];
        if (check[ch - 'a'])
            return false;
        check[ch-'a'] = true;
        while(s[j+1] == ch) {
            j++;
        }
        if (j == len - 1)
            return true;
    }

}

int main() {
    int n;
    cin >> n;
    bool check = true;
    int count = 0;

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        if(checker(s))
            count++;
    }

    cout << count;
}
