#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> deg(2 * n);
    for (auto &x : a) {
        cin >> x;
        x--;
        deg[x]++;
    }
    for (auto &x : b) {
        cin >> x;
        x--;
        deg[x]++;
    }
    vector<vector<PII>> adj(2 * n); // {point, edge_id}
    for (int i = 0; i < n; i++) {
        adj[a[i]].emplace_back(b[i], i);
        adj[b[i]].emplace_back(a[i], i);
    }

    int res = 0;
    for (auto x : deg) {
        if (x >= 2) {
            res += 2;
        } else {
            res += x;
        }
    }
    cout << res << '\n';

    vector<int> vis(2 * n);
    vector<int> used(2 * n); // whether edge i is decided
    vector<int> ra(n), rb(n);
    vector<int> ptr(2 * n);
    auto dfs = [&](auto &self, int u, int root, int dir) -> void {
        vis[u] = 1;
        while (ptr[u] < adj[u].size()) {
            auto [v, id] = adj[u][ptr[u]++];
            if (used[id]) {
                continue;
            }
            used[id] = 1;
            if (u == root) {
                dir ^= 1;
            }
            if (dir) {
                // son->fa
                ra[id] = v, rb[id] = u;
            } else {
                // fa->son
                ra[id] = u, rb[id] = v;
            }
            self(self, v, root, dir);
        }
    };
    for (int i = 0; i < 2 * n; i++) {
        if (!vis[i] && deg[i]) {
            dfs(dfs, i, i, 0);
        }
    }
    for (auto x : ra) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
    for (auto x : rb) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}