#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, kk;
    cin >> n >> m >> kk;
    kk++;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (kk, -1)));
    // write down from which direction it comes
    vector<vector<vector<PII>>> pre(n, vector<vector<PII>> (m, vector<PII> (kk)));
    for (int j = 0; j < m; j++) {
        dp[0][j][a[0][j] % kk] = a[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < kk; k++) {
                for (int t = 0; t < kk; t++) {
                    if ((t + a[i][j]) % kk != k) {
                        continue;
                    }
                    if (j - 1 >= 0 && dp[i - 1][j - 1][t] != -1 && dp[i - 1][j - 1][t] + a[i][j] > dp[i][j][k]) {
                        dp[i][j][k] = dp[i - 1][j - 1][t] + a[i][j];
                        pre[i][j][k] = {j - 1, t};
                    }
                    if (j + 1 < m && dp[i - 1][j + 1][t] != -1 && dp[i - 1][j + 1][t] + a[i][j] > dp[i][j][k]) {
                        dp[i][j][k] = dp[i - 1][j + 1][t] + a[i][j];
                        pre[i][j][k] = {j + 1, t};
                    }
                }
            }
        }
    }
    int res = -1, pos = -1;
    for (int j = 0; j < m; j++) {
        if (dp[n - 1][j][0] > res) {
            res = dp[n - 1][j][0];
            pos = j;
        }
    }
    if (res == -1) {
        cout << -1 << '\n';
        return;
    }
    cout << res << '\n' << pos + 1 << '\n';

    int i = n - 1, j = pos, k = 0;
    while (i > 0) {
        int nj = pre[i][j][k].first;
        int nk = pre[i][j][k].second;
        if (nj < j) {
            cout << "L";
        } else {
            cout << "R";
        }
        i--, j = nj, k = nk;
    }
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