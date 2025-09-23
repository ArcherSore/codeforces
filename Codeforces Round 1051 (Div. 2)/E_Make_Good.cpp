#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool check(string &s) {
    int t = 0;
    for (auto c : s) {
        if (c == '(') {
            t++;
        } else {
            t--;
        }
        if (t < 0) {
            return false;
        }
    }
    return t == 0;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if ((2 * count(s.begin(), s.end(), '(') - n) % 4) {
        cout << -1 << '\n';
        return;
    }
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            continue;
        }
        while (p < i || p < n - 1 && s[p] != s[p + 1]) {
            p++;
        }
        if (p == n - 1) {
            break;
        }
        s[i] ^= 1;
        s[p + 1] ^= 1;
    }
    // cerr << s << '\n';

    int dif = 2 * count(s.begin(), s.end(), '(') - n;
    p = n - 1;
    for (int i = n - 1, j = 0; i >= 0 && j < dif / 4; i--) {
        if (s[i] == ')') {
            continue;
        }
        while (p > i || p > 0 && s[p] != s[p - 1]) {
            p--;
        }
        if (p == 1) {
            break;
        }
        s[i] ^= 1;
        s[p - 1] ^= 1;
        j++;
    }
    if (check(s)) {
        cout << s << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}