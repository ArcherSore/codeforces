#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

LL sum(int l, int r, vector<LL> &pre) {
    return (pre[r] - (l ? pre[l - 1] : 0) + MOD) % MOD;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<LL>> dp(n, vector<LL> (m));
    vector<LL> pre(m);
    // init
    pre[0] = (g[n - 1][0] == 'X');
    for (int j = 1; j < m; j++) {
        pre[j] = pre[j - 1] + (g[n - 1][j] == 'X');
    }
    for (int j = 0; j < m; j++) {
        if (g[n - 1][j] == '#') {
            continue;
        }
        dp[n - 1][j] = sum(max(0, j - k), min(m - 1, j + k), pre);
    }
    // dp
    for (int i = n - 2; i >= 0; i--) {
        pre[0] = dp[i + 1][0];
        for (int j = 1; j < m; j++) {
            pre[j] = (pre[j - 1] + dp[i + 1][j]) % MOD;
        }
        int kk = sqrt(k * k - 1);
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                continue;
            }
            dp[i][j] = sum(max(0, j - kk), min(m - 1, j + kk), pre);
        }

        pre[0] = dp[i][0];
        for (int j = 1; j < m; j++) {
            pre[j] = (pre[j - 1] + dp[i][j]) % MOD;
        }
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                continue;
            }
            dp[i][j] = sum(max(0, j - k), min(m - 1, j + k), pre);
        }
    }

    LL res = 0;
    for (int j = 0; j < m; j++) {
        res = (res + dp[0][j]) % MOD;
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