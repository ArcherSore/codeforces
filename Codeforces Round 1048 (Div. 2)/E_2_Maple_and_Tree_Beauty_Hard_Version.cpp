#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 2e5;
bitset<N> dp;

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
    int mndep = 1e9;
    vector<int> cnt(mxdep + 1, 0);
    for (int u = 0; u < n; ++u) {
        cnt[depth[u]]++;
        if (adj[u].empty()) {
            mndep = min(mndep, depth[u]);
        }
    }

    int S = 0, res = 0;
    dp.reset();
    dp[0] = 1;
    for (int u = 0; u <= mndep; u++) {
        dp |= (dp << cnt[u]);
        S += cnt[u];
        int L = max(0, S - n + k);
        if (dp.test(L)) {
            res = u + 1;
            continue;
        }
        int nxt = dp._Find_next(L);
        if (nxt <= k) {
            res = u + 1;
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