#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> used(n), vis(n), parent(n, -1);
    auto dfs = [&](auto &self, int u, int fa) -> PII {
        PII best = {1, u};
        vis[u] = 1;
        parent[u] = fa;
        for (auto v : adj[u]) {
            if (v == fa || used[v]) {
                continue;
            }
            PII cur = self(self, v, u);
            cur.first += 1;
            best = max(best, cur);
        }
        return best;
    };

    vector<array<int, 3>> res;
    while (true) {
        if (count(used.begin(), used.end(), 0) == 0) {
            break;
        }
        vis.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (!used[i] && !vis[i]) {
                PII r1 = dfs(dfs, i, -1);
                PII r2 = dfs(dfs, r1.second, -1);
                res.push_back({r2.first, max(r1.second, r2.second), min(r1.second, r2.second)});

                int cur = r2.second;
                while (cur != -1) {
                    used[cur] = 1;
                    cur = parent[cur];
                }
            }
        }
    }

    sort(res.begin(), res.end(), greater<array<int, 3>>());
    for (auto [d, u, v] : res) {
        cout << d << ' ' << u + 1 << ' ' << v + 1 << ' ';
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