#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    string s;
    cin >> s;
    
    vector<int> pre(n);
    vector<int> suf(n);
    for (int i = 0; i < n; i++) {
        pre[i] = (i ? pre[i - 1] : 0) + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = (i < n - 1 ? suf[i + 1] : 0) + (s[i] - '0') * a[i];
    }

    int res = suf[0];
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int tot = 0;
            if (i) {
                tot += pre[i - 1];
            }
            if (i < n - 1) {
                tot += suf[i + 1];
            }
            res = max(res, tot);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}