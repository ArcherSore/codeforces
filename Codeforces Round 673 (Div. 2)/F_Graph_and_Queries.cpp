#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

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

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};

struct Info {
    int idx, mx;
    Info() : idx(0), mx(-inf) {}
    Info(int _idx, int _mx) : idx(_idx), mx(_mx) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    if (a.mx >= b.mx) {
        c = a;
    } else {
        c = b;
    }
    return c;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> node(n); // node weight
    for (auto &x : node) {
        cin >> x;
    }
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v, 0};
    }
    vector<pii> query(q);
    for (int i = 0; i < q; i++) {
        int op, x;
        cin >> op >> x;
        x--;
        query[i] = {op, x};
        if (op == 2) {
            edges[x].w = -1;
        }
    }

    // allocating edge weight
    int wcnt = 0;
    for (auto &e : edges) {
        if (e.w != -1) {
            e.w = wcnt++;
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        auto &[op, x] = query[i];
        if (op == 2) {
            edges[x].w = wcnt++;
        }
    }
    sort(edges.begin(), edges.end());

    // build kruskal tree
    int cnt = n;
    vector<vector<int>> adj(2 * n);
    vector<int> val(2 * n);
    DSU dsu(2 * n);
    for (auto &e : edges) {
        if (!dsu.same(e.u, e.v)) {
            adj[cnt].push_back(dsu.find(e.u));
            adj[cnt].push_back(dsu.find(e.v));
            dsu.merge(cnt, e.u);
            dsu.merge(cnt, e.v);
            val[cnt] = e.w;
            cnt++;
        }
    }
    adj.resize(cnt), val.resize(cnt);

    // dfs on tree
    const int LOG = __lg(cnt) + 1;
    vector<vector<int>> parent(LOG, vector<int> (cnt, -1));
    int dcnt = 0; // dfn index for leaf
    vector<int> dfn(n), mp(n); // dfn[u]->u
    vector<int> dmin(cnt, inf), dmax(cnt, -1); // min and max dfn index
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        parent[0][u] = fa;
        if (adj[u].empty()) {
            dfn[u] = dcnt++;
            mp[dfn[u]] = u;
            dmin[u] = dmax[u] = dfn[u];
            return;
        }
        for (int v : adj[u]) {
            self(self, v, u);
            dmin[u] = min(dmin[u], dmin[v]);
            dmax[u] = max(dmax[u], dmax[v]);
        }
    };
    for (int u = 0; u < cnt; u++) {
        if (dsu.find(u) == u) {
            dfs(dfs, u, -1);
        }
    }
    for (int k = 0; k < LOG - 1; k++) {
        for (int u = 0; u < cnt; u++) {
            if (parent[k][u] != -1) {
                parent[k + 1][u] = parent[k][parent[k][u]];
            } else {
                parent[k + 1][u] = -1;
            }
        }
    }
    auto jump = [&](int u, int limit) -> int {
        for (int i = LOG - 1; i >= 0; i--) {
            int nu = parent[i][u];
            if (nu != -1 && val[nu] < limit) {
                u = nu;
            }
        }
        return u;
    };

    vector<Info> info(n);
    for (int i = 0; i < n; i++) {
        info[i] = {i, node[mp[i]]};
    }
    SegmentTree<Info> sg(info);
    int limit = m; // can go through
    for (auto &[op, x] : query) {
        if (op == 1) {
            int u = jump(x, limit);
            auto [idx, mx] = sg.rangeQuery(dmin[u], dmax[u] + 1);
            cout << mx << '\n';
            sg.modify(idx, {idx, 0});

            // delete
            // cout << "idx: ";
            // for (int i = 0; i < n; i++) {
            //     cout << sg.rangeQuery(i, i + 1).idx << ' ';
            // }
            // cout << '\n';
            // cout << "val: ";
            // for (int i = 0; i < n; i++) {
            //     cout << sg.rangeQuery(i, i + 1).mx << ' ';
            // }
            // cout << '\n';
        } else {
            limit--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}