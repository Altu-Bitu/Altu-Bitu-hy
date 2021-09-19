
#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> s(21, false);

    int n;
    cin >> n;

    string str;

    for (int i = 0; i < n; i++) {
        cin >> str;
        int x;
        if (str == "all") {
            for (int i = 1; i < 21; i++) {
                s[i] = true;
            }
        } else if (str == "empty") {
            for (int i = 1; i < 21; i++) {
                s[i] = false;
            }
        } else if (str == "add") {
            cin >> x;
            if (!s[x])
                s[x] = true;
        } else if (str == "remove") {
            cin >> x;
            if (s[x])
                s[x] = false;
        } else if (str == "check") {
            cin >> x;
            if (s[x])
                cout << '1' << '\n';
            else
                cout << '0' << '\n';
        } else {
            cin >> x;
            s[x] = !s[x];
        }
    }
}


