#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

void solve() {
    LL n, l, r;
    cin >> n >> l >> r;
    array<LL, 3> cnt;
    for (int i = 0; i < 3; i++) {
        cnt[i] = (r + 3 - i) / 3 - (l - 1 + 3 - i) / 3;
    }
    vector<vector<LL>> dp(n, vector<LL> (3));
    dp[0][0] = cnt[0], dp[0][1] = cnt[1], dp[0][2] = cnt[2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][0] * cnt[0] + dp[i - 1][1] * cnt[2] + dp[i - 1][2] * cnt[1]) % MOD;
        dp[i][1] = (dp[i - 1][0] * cnt[1] + dp[i - 1][1] * cnt[0] + dp[i - 1][2] * cnt[2]) % MOD;
        dp[i][2] = (dp[i - 1][0] * cnt[2] + dp[i - 1][1] * cnt[1] + dp[i - 1][2] * cnt[0]) % MOD;
    }
    cout << dp[n - 1][0];
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