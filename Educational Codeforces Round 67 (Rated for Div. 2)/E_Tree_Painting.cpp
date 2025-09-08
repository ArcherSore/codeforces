#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> siz(n);
    auto dfs1 = [&](auto &&self, int u, int p) -> void {
        siz[u] = 1;
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
        }
    };
    dfs1(dfs1, 0, -1);
    
    vector<ll> dp(n);
    dp[0] = accumulate(siz.begin(), siz.end(), 0LL);
    auto dfs2 = [&](auto &&self, int u, int p) -> void {
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            dp[v] = dp[u] - 2 * siz[v] + n;
            self(self, v, u);
        }
    };
    dfs2(dfs2, 0, -1);
    ll res = *max_element(dp.begin(), dp.end());
    cout << res;
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