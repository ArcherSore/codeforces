#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }

    vector<int> depth(n, 0);
    auto dfs = [&](auto &&self, int u) -> void {
        for (int v : adj[u]) {
            depth[v] = depth[u] + 1;
            self(self, v);
        }
    };
    dfs(dfs, 0);

    int mxdep = *max_element(depth.begin(), depth.end());
    vector<int> cnt(mxdep + 2, 0);
    for (int u = 0; u < n; ++u) {
        cnt[depth[u] + 1]++;
    }

    int mndep = 1e9;
    for (int u = 0; u < n; ++u) {
        if (adj[u].empty()) {
            mndep = min(mndep, depth[u] + 1);
        }
    }

    int small = min(k, n - k);
    int large = n - small;
    vector<int> dp(small + 1, 0);
    dp[0] = 1;
    
    ll S = 0;
    int res = 0;
    for (int d = 1; d <= mndep; ++d) {
        int w = cnt[d];

        if (w <= small) {
            for (int x = small; x >= w; --x) {
                if (dp[x - w]) {
                    dp[x] = 1;
                }
            }
        }
        S += w;

        ll L = max(0LL, S - large);
        if (L > small) {
            break;
        }
        ll R = min<ll>(small, S);

        bool ok = false;
        for (int s = L; s <= R; s++) {
            if (dp[s]) { 
                ok = true; 
                break; 
            }
        }
        if (ok) {
            res = d;
        }
    }

    cout << res << '\n';
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