#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> f;
    
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }
};

struct ST {
    int n, LOG;
    vector<vector<int>> stmax, stmin;
    
    ST(const vector<int> &a) {
        init(a);
    }

    void init(const vector<int> &a) {
        n = a.size();
        LOG = __lg(n) + 1;
        stmax.assign(LOG, vector<int> (n));
        stmin.assign(LOG, vector<int> (n));
        for (int u = 0; u < n; u++) {
            stmax[0][u] = stmin[0][u] = a[u];
        }
        for (int k = 0; k < LOG - 1; k++) {
            for (int u = 0; u + (1 << k + 1) < n; u++) {
                stmax[k + 1][u] = max(stmax[k][u], stmax[k][u + (1 << k)]);
                stmin[k + 1][u] = min(stmin[k][u], stmin[k][u + (1 << k)]);
            }
        }
    }

    // 0-index, [l, r)
    pii query(int l, int r) {
        int k = __lg(r - l);
        int mn = min(stmin[k][l], stmin[k][r - (1 << k)]);
        int mx = max(stmax[k][l], stmax[k][r - (1 << k)]);
        return {mn, mx};
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v, i + 1};
    }
    sort(edges.begin(), edges.end());

    int cnt = n;
    vector<vector<int>> adj(2 * n);
    vector<int> val(2 * n);
    DSU dsu(2 * n);
    for (auto &[u, v, w] : edges) {
        if (!dsu.same(u, v)) {
            adj[cnt].push_back(dsu.find(u));
            adj[cnt].push_back(dsu.find(v));
            dsu.merge(cnt, u);
            dsu.merge(cnt, v);
            val[cnt] = w;
            cnt++;
        }
    }
    adj.resize(cnt), val.resize(cnt);

    int cntd = 0;
    const int LOG = __lg(cnt) + 1;
    vector<vector<int>> parent(LOG, vector<int> (cnt, -1));
    vector<int> depth(cnt);
    vector<int> dfn(cnt), mp(cnt); // mp: dfn->idx
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        dfn[u] = cntd++;
        mp[dfn[u]] = u;
        parent[0][u] = fa;
        for (int v : adj[u]) {
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, cnt - 1, -1);
    for (int k = 0; k < LOG - 1; k++) {
        for (int u = 0; u < cnt; u++) {
            if (parent[k][u] != -1) {
                parent[k + 1][u] = parent[k][parent[k][u]];
            } else {
                parent[k + 1][u] = parent[k][u];
            }
        }
    }
    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int d = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if (d & (1 << i)) {
                u = parent[i][u];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = LOG - 1; i >= 0; i--) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    };

    ST st(dfn);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        pii t = st.query(l, r + 1);
        int idx = lca(mp[t.first], mp[t.second]);
        cout << val[idx] << ' ';
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