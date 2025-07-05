#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e16;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] < k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int q;
    cin >> q;
    vector<int> edges;
    vector<PII> ops;
    for (int i = 0; i < q; i++) {
        int t, v, x;
        cin >> t;
        if (t == 1) {
            cin >> v;
            v--;
            edges.push_back(v);
            ops.push_back({v, 2e9});
        } else {
            cin >> v >> x;
            v--;
            ops.push_back({v, x});
        }
    }

    int n = edges.size() + 1, sz = 0;
    vector<vector<int>> adj(n);
    for (int v : edges) {
        adj[v].push_back(++sz);
    }
    int tm = 0;
    vector<int> tin(n), tout(n);
    auto dfs = [&](auto &self, int u, int fa) -> void {
        tin[u] = tm++;
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
        tout[u] = tm;
    };
    dfs(dfs, 0, -1);

    sz = 0;
    Fenwick<LL> fw(n);
    fw.add(1, INF);
    for (auto [v, x] : ops) {
        if (x == 2e9) {
            LL d = fw.rangeSum(0, tin[++sz] + 1);
            fw.add(tin[sz], -d);
            if (tin[sz] + 1 <= n) {
                fw.add(tin[sz] + 1, d);
            }
        } else {
            fw.add(tin[v], x);
            if (tout[v] + 1 <= n) {
                fw.add(tout[v], -x);
            }
        }

        // debug
        // vector<LL> res(n);
        // for (int i = 0; i < n; i++) {
        //     res[i] = fw.rangeSum(0, tin[i] + 1);
        // }
        // for (auto x : res) {
        //     cout << x << ' ';
        // }
        // cout << "\n\n";
    }

    vector<LL> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = fw.rangeSum(0, tin[i] + 1);
    }
    for (auto x : res) {
        cout << x << ' ';
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