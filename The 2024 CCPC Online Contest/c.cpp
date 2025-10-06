#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int root;
    vector<int> vis(n);
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        x--;
        vis[x] = 1;
        root = x;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    vector<int> siz(n);
    auto dfs = [&](auto &&self, int u, int p) -> void {
        int ssiz = 0, cnt = 0;
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            if (siz[v] == -1) {
                cnt++;
            } else {
                ssiz += siz[v];
            }
        }
        if (vis[u] || !vis[u] && cnt) {
            res += (ssiz + 1) / 2;
            if (ssiz % 2 && p != -1 && !vis[p]) {
                siz[u] = -1;
            } else {
                siz[u] = 0;
            }
        } else {
            siz[u] = ssiz + 1;
        }
    };
    dfs(dfs, root, -1);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}