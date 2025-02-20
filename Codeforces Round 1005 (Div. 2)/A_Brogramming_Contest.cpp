#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int p = 0;
    while (p < n && s[p] == '0') {
        p++;
    }
    if (p == n) {
        cout << 0 << '\n';
        return;
    } 
    int res = 1;
    for (int i = p + 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            res++;
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