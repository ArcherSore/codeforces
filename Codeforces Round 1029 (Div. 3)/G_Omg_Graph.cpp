#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct DSU {
    vector<int> f, mn, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        mn.assign(n, 1e9 + 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same (int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y, int w) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        mn[x] = min({mn[x], mn[y], w});
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj(n);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int res = 2e9 + 1, mx = 0;
    for (auto [w, u, v] : edges) {
        dsu.merge(u, v, w);
        mx = max(mx, w);
        if (dsu.find(0) == dsu.find(n - 1)) {
            res = min(res, mx + dsu.mn[dsu.find(0)]);
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