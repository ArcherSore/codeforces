#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    LL res = 0;
    vector<LL> v(n);
    for (LL &x : v) {
        cin >> x;
        res += x;
    }
    if (n == 1) {
        cout << res << '\n';
        return;
    }
    auto dfs = [&](auto &self, vector<LL> &v) -> void {
        int n = v.size();
        if (n == 1) {
            res = max(res, abs(v.back()));
            return;
        }
        LL sum = 0;
        vector<LL> t(n - 1);
        for (int i = 1; i < n; i++) {
            t[i - 1] = v[i] - v[i - 1];
            sum += t[i - 1];
        }
        res = max(res, abs(sum));
        self(self, t);
    };
    dfs(dfs, v);
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