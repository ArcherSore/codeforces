#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<vector<LL>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LL k, x;
    cin >> k >> x;

    // =k <k >k
    vector<vector<vector<LL>>> dp(n, vector<vector<LL>> (x + 1, vector<LL> (3, 0)));
    auto dfs = [&](auto &self, int u, int fa) -> void {
        dp[u][1][0] = 1;
        dp[u][0][1] = k - 1;
        dp[u][0][2] = m - k;
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);

            vector<vector<LL>> tmp(x + 1, vector<LL> (3, 0));
            for (int s = 0; s < 3; s++) {
                for (int x1 = 0; x1 <= x; x1++) { // the count of 'k' used for u
                    if (dp[u][x1][s] == 0) {
                        continue;
                    }
                    for (int x2 = 0; x1 + x2 <= x; x2++) { // the count of 'k' used for v
                        LL tot = 0;
                        if (s == 0) {
                            tot = dp[v][x2][1];
                        } else if (s == 1) {
                            tot = (dp[v][x2][0] + dp[v][x2][1] + dp[v][x2][2]) % MOD;
                        } else {
                            tot = (dp[v][x2][1] + dp[v][x2][2]) % MOD;
                        }

                        tmp[x1 + x2][s] = (tmp[x1 + x2][s] + tot * dp[u][x1][s] % MOD) % MOD;
                    }
                }
            }

            for (int c = 0; c <= x; c++) {
                for (int s = 0; s < 3; s++) {
                    dp[u][c][s] = tmp[c][s];
                }
            }
        }
    };
    dfs(dfs, 0, -1);

    LL res = 0;
    for (int c = 0; c <= x; c++) {
        for (int s = 0; s < 3; s++) {
            res = (res + dp[0][c][s]) % MOD;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}