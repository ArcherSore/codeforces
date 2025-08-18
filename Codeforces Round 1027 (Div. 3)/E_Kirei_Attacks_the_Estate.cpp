#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<LL>> dp(n, vector<LL> (2, -INF));
    dp[0][0] = a[0], dp[0][1] = -a[0];
    auto dfs = [&](auto &self, int u, int fa) -> void {
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            dp[v][0] = max(a[v], a[v] + dp[u][1]);
            dp[v][1] = max(-a[v], -a[v] + dp[u][0]);
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        cout << dp[i][0] << ' ';
    }
    cout << '\n';
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