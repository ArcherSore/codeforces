#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n), c(n);
    for (auto &x : s) {
        cin >> x;
    }
    for (auto &x : c) {
        cin >> x;
    }

    vector<vector<int>> dp(n, vector<int> (3, INF));
    for (int i = 0; i < n; i++) {
        dp[i][0] = c[i];
    }
    for (int k = 1; k <= 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] < s[j]) {
                    dp[j][k] = min(dp[j][k], dp[i][k - 1] + c[j]);
                }
            }
        }
    }
    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[i][2]);
    }
    cout << (res == INF ? -1 : res);
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