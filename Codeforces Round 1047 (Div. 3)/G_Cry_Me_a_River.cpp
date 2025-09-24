#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    vector<int> siz(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        siz[u]++;
    }
    vector<int> lcnt(n, 0);
    vector<vector<char>> dp(n, vector<char> (2, 1));
    auto bfs = [&](int ru, int rc) -> void {
        queue<pii> q;
        q.push({ru, rc});
        while (!q.empty()) {
            auto [u, c] = q.front();
            q.pop();
            if (dp[u][c] == 0) {
                continue;
            }
            dp[u][c] = 0;
            
            if (c == 0) {
                for (auto v : adj[u]) {
                    q.push({v, c ^ 1});
                }
            } else {
                for (auto v : adj[u]) {
                    if (++lcnt[v] == siz[v]) {
                        q.push({v, c ^ 1});
                    }
                }
            }
        }
    };
    while (q--) {
        int x, u;
        cin >> x >> u;
        u--;
        if (x == 1) {
            bfs(u, 0);
            bfs(u, 1);
            continue;
        }
        cout << (dp[u][0] ? "YES" : "NO") << '\n';
    }
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