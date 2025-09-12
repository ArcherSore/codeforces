#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int rm(int x, int p) {
    int lo = x & ((1 << p) - 1);
    int hi = (x >> p + 1) << p;
    return lo | hi;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        c[i]--;
    }
    if (m == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<vector<char>> dp(2, vector<char> (1 << n));
    dp[0][1] = dp[1][1] = 1;
    dp[0][0] = dp[1][0] = 0;
    for (int i = 2; i <= n; i++) {
        // cerr << i << '\n';
        vector<vector<char>> tdp(2, vector<char> (1 << n));
        fill(tdp[1].begin(), tdp[1].end(), 1);
        for (int mask = 0; mask < (1 << i); mask++) {
            for (int j = 1; j <= k && c[j] < i; j++) {
                tdp[0][mask] = max(tdp[0][mask], dp[1][rm(mask, c[j])]);
                tdp[1][mask] = min(tdp[1][mask], dp[0][rm(mask, c[j])]);
            }
        }
        dp = tdp;
    }
    ll res = accumulate(dp[0].begin(), dp[0].end(), 0LL) + (1LL << n);
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