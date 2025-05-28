#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> b(n);
    for (auto &x : b) {
        cin >> x;
    }
    vector<vector<pair<LL, LL>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    LL le = 1, ri = 1e18, mid;
    LL res = -1;
    auto check = [&](LL mid) -> bool {
        vector<LL> dp(n, -1);
        dp[0] = min(b[0], mid);
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                if (min(dp[u], mid) >= w) {
                    dp[v] = max(dp[v], min(dp[u] + b[v], mid));
                }
            }
        }
        return dp[n - 1] != -1;
    };
    // 选择mid个battery可以到达
    while (le <= ri) {
        mid = (le + ri) / 2;
        if (check(mid)) {
            res = mid;
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
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