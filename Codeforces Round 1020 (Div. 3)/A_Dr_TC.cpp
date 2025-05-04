#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = count(s.begin(), s.end(), '1');
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            res += cnt + 1;
        } else {
            res += cnt - 1;
        }
    }
    cout << res << '\n';
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