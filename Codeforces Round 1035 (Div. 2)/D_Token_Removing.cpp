#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<vector<LL>> dp(n + 2, vector<LL> (n + 1));
    dp[n + 1][0] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (dp[i][j] + dp[i + 1][j]) % m;
            if (j) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j - 1] * (n - i - j + 2) % m * i % m) % m;
            }
        }
    }
    LL res = 0;
    for (int j = 0; j <= n; j++) {
        res = (res + dp[1][j]) % m;
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