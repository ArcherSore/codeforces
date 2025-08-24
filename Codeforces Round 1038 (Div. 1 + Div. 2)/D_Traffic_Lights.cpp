#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    vector<int> f(n, inf);
    f[0] = 0;
    for (int t = 0; ; t++) {
        vector<int> nf(n, inf);
        for (int u = 0; u < n; u++) {
            if (f[u] == inf) {
                continue;
            }
            // wait
            nf[u] = min(nf[u], f[u] + 1);
            // move
            nf[adj[u][t % deg[u]]] = min(nf[adj[u][t % deg[u]]], f[u]);
        }
        f = nf;
        if (f[n - 1] < inf) {
            cout << t + 1 << ' ' << f[n - 1] << '\n';
            break;
        }
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