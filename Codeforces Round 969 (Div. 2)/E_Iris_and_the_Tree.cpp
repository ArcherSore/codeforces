#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct Tree {
    int n, LOG;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<vector<int>> adj;
    vector<int> subtr;

    Tree(int n) : n(n) {
        LOG = __lg(n) + 1;
        parent.assign(LOG, vector<int>(n, -1));
        depth.assign(n, 0);
        adj.resize(n);
        subtr.assign(n, 1);
    }

    // [attention] 
    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        parent[0][u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            subtr[u] += subtr[v];
        }
    }

    void init(int root = 0) {
        dfs(root, -1);
        for (int k = 0; k < LOG - 1; k++) {
            for (int u = 0; u < n; u++) {
                if (parent[k][u] == -1) {
                    parent[k + 1][u] = -1;
                } else {
                    parent[k + 1][u] = parent[k][parent[k][u]];
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
    }

    int dist(int u, int v) {
        // calculate the distance between node u and node v
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

void solve() {
    int n;
    LL w;
    cin >> n >> w;
    Tree tr(n);
    for (int i = 1, p; i < n; i++) {
        cin >> p;
        p--;
        tr.add(i, p);
    }
    tr.init();

    vector<int> fre(n);
    for (int i = 0; i < n; i++) {
        fre[(i + 1) % n] = tr.dist(i, (i + 1) % n);
    }
    int cnt = n;
    LL sum = 0;
    for (int i = 1; i < n; i++) {
        int x;
        LL y;
        cin >> x >> y;
        x--;

        fre[x]--;
        if (fre[x] == 0) {
            cnt--;
        }
        fre[(x + tr.subtr[x]) % n]--;
        if (fre[(x + tr.subtr[x]) % n] == 0) {
            cnt--;
        }

        sum += y;
        LL res = 2 * sum + cnt * (w - sum);
        cout << res << ' ';
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