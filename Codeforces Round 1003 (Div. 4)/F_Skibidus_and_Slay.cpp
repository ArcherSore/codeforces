#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        w[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res(n);
    auto dfs = [&](auto &self, int u, int fa) -> void {
        map<int, int> cnt;
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);

            cnt[w[v]]++;
            // #1 该节点和子节点相等
            if (w[v] == w[u]) {
                res[w[v]] = 1;
            }
            // #2 子节点和父节点相等
            if (fa != -1 && w[v] == w[fa]) {
                res[w[v]] = 1;
            }
        }
        // #3 存在两个子节点相等
        for (auto [x, c] : cnt) {
            if (c > 1) {
                res[x] = 1;
            }
        }
    };
    dfs(dfs, 0, -1);
    for (auto x : res) {
        cout << x;
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