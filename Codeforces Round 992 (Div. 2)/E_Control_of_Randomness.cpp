#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

struct State {
    int u, deg, parity;
    bool operator<(const State &other) const {
        return other.deg < deg;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    vector<int> deg(n), depth(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u] += 1;
        deg[v] += 1;
    }

    auto dfs = [&](auto &self, int u, int fa) -> void {
        if (u != 0) {
            depth[u] = depth[fa] + 1;
        }
        for (auto v : g[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);

    while (q--) {
        int v, p;
        cin >> v >> p;
        v--;

        vector<int> path;
        while (v != 0) {
            path.push_back(v);
            for (auto u : g[v]) {
                if (depth[u] < depth[v]) {
                    v = u;
                    break;
                }
            }
        }

        vector<State> d;
        for (int i = 0; i < path.size(); i++) {
            d.push_back({path[i], deg[path[i]], i & 1});
        }
        sort(d.begin(), d.end());

        LL res = 0;
        for (auto t : d) {
            if (t.parity == 0 || t.parity == 1 && p) {
                res = (res + 1) % MOD;
                if (t.parity) {
                    p--;
                }
            } else {
                res = (res + 2 * t.deg - 1) % MOD;
            }
        }
        cout << res << '\n';
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

/*
奇数步的时候，靠近1的代价为x=1
偶数步的时候
    支付：x=1
    不支付：x=2d-1
    证明：
        该点度为d，1个相邻点是靠近1。
        靠近1的期望是x
        x = 1/d * 1 + (d-1)/d * (1 + 1 + x)
        x=2d-1
    
所以支付能够节省更多的点
*/