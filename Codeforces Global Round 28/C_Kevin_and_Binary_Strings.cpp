#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int p = 0;
    for (auto c : s) {
        if (c == '0') {
            break;
        } else {
            p++;
        }
    }
    if (p == s.size()) {
        cout << 1 << ' ' << s.size() << ' ' << 1 << ' ' << 1 << '\n';
        return;
    }
    int zeros = 0;
    for (int i = p; i < s.size(); i++) {
        if (s[i] == '1') {
            break;
        } else {
            zeros++;
        }
    }
    cout << 1 << ' ' << s.size() << ' ';
    if (zeros >= p) {
        cout << 1 << ' ' << s.size() - p << '\n';
    } else {
        cout << 1 + (p - zeros) << ' ' << s.size() - zeros << '\n';
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