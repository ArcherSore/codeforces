#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    vector<vector<int>> dp(n, vector<int> (4));
    for (int i = 0; i < n; i++) {
        dp[i][0] = (i ? dp[i - 1][0] : 0) + (v[i] == 1);
        dp[i][1] = max(i ? dp[i - 1][0] : 0, (i ? dp[i - 1][1] : 0)) + (v[i] == 2);
        dp[i][2] = max(i ? dp[i - 1][1] : 0, (i ? dp[i - 1][2] : 0)) + (v[i] == 1);
        dp[i][3] = max(i ? dp[i - 1][2] : 0, (i ? dp[i - 1][3] : 0)) + (v[i] == 2);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]}) << '\n';
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