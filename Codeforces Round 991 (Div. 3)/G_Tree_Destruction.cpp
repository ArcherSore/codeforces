#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    int ans = 0;
    vector<int> f(n);
    auto dfs = [&](auto &self, int u, int fa) -> void {
        f[u] = deg[u] - 2;
        vector<int> sub;
        for (auto v : g[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            if (f[v] > 0) {
                sub.push_back(f[v]);
            }
        }
        sort(sub.begin(), sub.end(), greater<int> ());
        int tmp = deg[u] - 2;
        if (sub.size() > 0) {
            tmp += sub[0];
            f[u] += sub[0];
        }
        if (sub.size() > 1) {
            tmp += sub[1];
        }
        ans = max(ans, tmp + 2);
    };

    dfs(dfs, 0, -1);

    for (auto x : f) {
        ans = max(ans, x + 2);
    }

    for (auto d : deg) {
        ans = max(ans, d);
    }
    cout << ans << '\n';
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
