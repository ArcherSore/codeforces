#include <bits/stdc++.h>
using namespace std;

int cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < 26; i++) {
        int tot = 0;
        for (auto &x : s) {
            tot += cnt[(x - 'A' + i) % 26];
        }
        res = max(res, tot);
    }

    cout << res << '\n';

    return 0;
}

// 16:00