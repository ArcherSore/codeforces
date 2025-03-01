#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, st, ed;
    cin >> n >> st >> ed;
    st--, ed--;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n);
    auto dfs = [&](auto &self, int u, int fa) -> void {
        if (fa == -1) {
            dist[u] = 0;
        } else {
            dist[u] = dist[fa] + 1;
        }
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs(dfs, ed, -1);

    vector<int> res(n);
    for (int i = 0; i < n; i++){
        res[i] = i;
    }

    sort(res.begin(), res.end(), [&](int a, int b){
        return dist[a] > dist[b];
    });

    for (int i = 0; i < n; i++){
        cout << res[i] + 1 << ' ';
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