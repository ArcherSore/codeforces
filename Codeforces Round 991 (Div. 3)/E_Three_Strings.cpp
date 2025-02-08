#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i < n) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (a[i] != c[i + j]));
            }
            if (j < m) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (b[j] != c[i + j]));
            }
        }
    }

    cout << dp[n][m] << '\n';
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