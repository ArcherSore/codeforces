#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    int p = find(deg.begin(), deg.end(), 2) - deg.begin();
    if (p == n) {
        cout << "NO\n";
        return;
    }
    vector<int> parent(n), depth(n), subtree(n);
    auto dfs = [&](auto &self, int u, int fa, int flag) -> void {
        subtree[u] = flag;
        parent[u] = fa;
        for (auto v : adj[u]) {
            if (fa == v) {
                continue;
            }
            depth[v] = depth[u] + 1;
            if (u == p) {
                self(self, v, u, 1);
            } else {
                self(self, v, u, flag);
            }
        }
    };
    int root = 0;
    if (p == 0) {
        root = 1;
    }
    dfs(dfs, root, -1, 0);

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (i == root) {
            continue;
        }
        if (subtree[i]) {
            if (depth[i] % 2) {
                cout << i + 1 << ' ' << parent[i] + 1 << '\n';
            } else {
                cout << parent[i] + 1 << ' ' << i + 1 << '\n';
            }
        } else {
            if (depth[i] % 2) {
                cout << parent[i] + 1 << ' ' << i + 1 << '\n';
            } else {
                cout << i + 1 << ' ' << parent[i] + 1 << '\n';
            }
        }
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