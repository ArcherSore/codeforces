#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Tree {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> parent, adj;
    vector<vector<int>> up, cost;
    Tree() : n(0) {}
    Tree(int n_) {
        init(n_);
    }
    void init(int n_) {
        n = n_;
        LOG = __lg(n + 1);
        depth.assign(n, 0);
        parent.assign(LOG, vector<int> (n, -1));
        adj.resize(n);
        up.assign(LOG, vector<int> (n, -1));
        cost.assign(LOG, vector<int> (n, -1));
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void dfs(int u, int p) {
        parent[0][u] = p;
        for (auto v : adj[u]) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    void work() {
        dfs(n - 1, -1);
        for (int k = 0; k < LOG - 1; k++) {
            for (int u = 0; u < n; u++) {
                if (parent[k][u] == -1) {
                    parent[k + 1][u] = -1;
                } else {
                    parent[k + 1][u] = parent[k][parent[k][u]];
                }
            }
        }

        for (int u = 0; u < n - 1; u++) {
            int ans = lca(u, u + 1);
            up[0][u] = ans;
            cost[0][u] = depth[u] + depth[u + 1] - 2 * depth[ans];
        }
        for (int k = 0; k < LOG - 1; k++) {
            for (int u = 0; u < n - 1; u++) {
                if (up[k][u] == -1) {
                    up[k + 1][u] = -1;
                    cost[k + 1][u] = -1;
                } else {
                    up[k + 1][u] = up[k][up[k][u]];
                    cost[k + 1][u] = cost[k][u] + cost[k][up[k][u]];
                }
            }
        }
    }
    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int d = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if (d >> i & 1) {
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
    }
    int count(int u, int r) {
        // jump from u until hitting the limit r
        if (u > r) {
            return 0;
        }
        int v = u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (parent[i][v] != -1 && parent[i][v] <= r) {
                v = parent[i][v];
            }
        }
        return depth[u] - depth[v] + 1;
    }
    int jumpl(int &l, int r) {
        int res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][l] != -1 && up[i][l] <= r) {
                res += cost[i][l];
                l = up[i][l];
            }
        }
        return res;
    }
    int solve(int l, int r) {
        int cur = l;
        int res = jumpl(cur, r);
        res += count(cur, r) + count(cur + 1, r);
        return res;
    }
};

void solve() {
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<int> f(n, n); // the nearest step from position i, n means infinity
    int l = 0, r = 0;
    while (l < n) {
        while (r < n && (r - l < 2 || a[r] - a[l] <= z)) {
        // while (r < n && a[r] - a[l] <= z) {
            r++;
        }
        f[l] = r;
        l++;
    }
    // for (auto x : f) {
    //     cerr << x << ' ';
    // }
    // cerr << '\n';

    // f[i]->i, n is the root
    Tree tr(n + 1);
    for (int i = 0; i < n; i++) {
        tr.addEdge(f[i], i);
    }
    tr.work();

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << tr.solve(l, r) << endl;
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