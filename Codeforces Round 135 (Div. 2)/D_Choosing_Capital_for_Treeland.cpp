#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<pii>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    vector<ll> flip(n);
    auto dfs1 = [&](auto &&self, int u, int p) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            flip[u] += flip[v] + w;
        }
    };
    dfs1(dfs1, 0, -1);

    // for (int i = 0; i < n; i++) {
    //     cerr << flip[i] << ' ';
    // }
    // cerr << '\n';

    vector<ll> dp(n);
    dp[0] = flip[0];
    auto dfs2 = [&](auto &&self, int u, int p) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == p) {
                continue;
            }
            dp[v] = dp[u] + (w ? -1 : 1);
            self(self, v, u);
        }
    };
    dfs2(dfs2, 0, -1);

    // for (int i = 0; i < n; i++) {
    //     cerr << dp[i] << ' ';
    // }
    // cerr << '\n';

    ll mn = *min_element(dp.begin(), dp.end());
    cout << mn << '\n';
    for (int i = 0; i < n; i++) {
        if (dp[i] == mn) {
            cout << i + 1 << ' ';
        }
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