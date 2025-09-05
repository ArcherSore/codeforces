#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 1e6;
const ll mod = 998244353;

vector<ll> inv(N + 1);

ll fpow(ll a, ll x) {
    ll res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

void init() {
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}


struct DSU {
    vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pii> edges;
    edges.reserve(n - 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.emplace_back(u, v);
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const int LOG = __lg(n) + 1;
    vector<vector<int>> parent(n, vector<int> (LOG));
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        parent[u][0] = fa;
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);
    for (int k = 0; k < LOG - 1; k++) {
        for (int u = 0; u < n; u++) {
            if (parent[u][k] != -1) {
                parent[u][k + 1] = parent[parent[u][k]][k];
            } else {
                parent[u][k + 1] = -1;
            }
        }
    }

    ll res = 1;
    DSU dsu(n);
    auto check = [&](int u, int v) -> bool {
        int cu = dsu.find(u), cv = dsu.find(v);
        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[u][k] != -1 && dsu.find(parent[u][k]) == cu) {
                u = parent[u][k];
            }
            if (parent[v][k] != -1 && dsu.find(parent[v][k]) == cv) {
                v = parent[v][k];
            }
        }
        u = parent[u][0], v = parent[v][0];
        if (u != -1 && dsu.find(u) == cv || v != -1 && dsu.find(v) == cu) {
            return true;
        }
        return false;
    };
    for (auto &[u, v] : edges) {
        if (check(u, v)) {
            res = res * inv[dsu.size(u)] % mod * inv[dsu.size(v)] % mod;
            dsu.merge(u, v);
        } else {
            cout << 0;
            return;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}