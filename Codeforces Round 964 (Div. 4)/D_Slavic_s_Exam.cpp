#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s, t;
    cin >> s >> t;
    int p = 0;
    for (int i = 0; i < t.size(); i++) {
        while (p < s.size() && s[p] != '?' && s[p] != t[i]) {
            p++;
        }
        if (p == s.size()) {
            cout << "NO\n";
            return;
        }
        s[p] = t[i];
        p++;
    }
    for (auto &c : s) {
        if (c == '?') {
            c = 'a';
        }
    }
    cout << "YES\n" << s << '\n';
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