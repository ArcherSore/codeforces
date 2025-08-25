#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

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

    vector<int> sz(n);
    vector<int> del;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            if (sz[u] != -1 && sz[v] != -1) {
                sz[u] += sz[v];
            }
        }

        if (sz[u] == 3 && p != -1) {
            del.push_back(p);
            sz[p] = -1;
        }
        if (sz[u] > 3) {
            del.push_back(u);
            sz[u] = -1;
        }
    };
    dfs(dfs, 0, -1);
    sort(del.begin(), del.end());
    del.erase(unique(del.begin(), del.end()), del.end());

    vector<pii> res;
    vector<int> vis(n);
    for (auto x : del) {
        vis[x] = 1;
        res.push_back({1, x + 1});
        res.push_back({2, x + 1});
    }
    auto work = [&](int tu) -> void {
        queue<int> q;
        q.push(tu);
        int mid = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (vis[u]) {
                continue;
            }
            vis[u] = 1;
            int sz = 0;
            for (int v : adj[u]) {
                if (vis[v]) {
                    continue;
                }
                q.push(v);
                sz++;
            }
            if (sz == 2) {
                mid = u;
            } else {
                res.push_back({1, u + 1});
                if (mid != -1) {
                    res.push_back({1, mid + 1});
                    mid = -1;
                }
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        work(i);
    }
    cout << res.size() << '\n';
    for (auto [o, x] : res) {
        cout << o << ' ' << x << '\n';
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