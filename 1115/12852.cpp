//
// Created by LG on 2021-11-11.
//
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int main() {
    int n;
    cin >> n;
    vector<ci> count(n + 1, {0, 0});

    if (n % 3 == 0) {
        count[n / 3] = {1, n};
    }
    if (n % 2 == 0) {
        count[n / 2] = {1, n};
    }
    count[n - 1] = {1, n};

    for (int i = n - 1; i > 1; i--) {
        if (count[i].first == 0)
            continue;
        if (i % 3 == 0) {
            if (count[i / 3].first == 0)
                count[i / 3] = {count[i].first + 1, i};
            else {
                if (count[i / 3].first > count[i].first + 1)
                    count[i / 3] = {count[i].first + 1, i};
            }
        }
        if (i % 2 == 0) {
            if (count[i / 2].first == 0)
                count[i / 2] = {count[i].first + 1, i};
            else {
                if (count[i / 2].first > count[i].first + 1)
                    count[i / 2] = {count[i].first + 1, i};
            }
        }
        if (count[i - 1].first == 0)
            count[i - 1] = {count[i].first + 1, i};
        else {
            if (count[i - 1].first > count[i].first + 1)
                count[i - 1] = {count[i].first + 1, i};
        }
    }

    int ans = count[1].first;
    cout << ans << '\n';
    vector<int> path(ans + 1);
    path[0] = 1;
    for (int i = 0; i < ans; i++)
        path[i + 1] = count[path[i]].second;

    for (int i = ans; i >= 0; i--)
        cout << path[i] << ' ';
}

