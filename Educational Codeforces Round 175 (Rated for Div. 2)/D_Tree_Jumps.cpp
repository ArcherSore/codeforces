#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> fa(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int f;
        cin >> f;
        f--;
        fa[i] = f;
        adj[f].push_back(i);
    }

    queue<PII> q;
    vector<LL> dp(n);
    dp[0] = 1;
    for (auto v : adj[0]) {
        dp[v] = 1;
        for (auto u : adj[v]) {
            q.push({u, 2});
        }
    }
    vector<LL> sum = {1, (int)adj[0].size()};

    while (!q.empty()) {
        int u = q.front().first;
        int lvl = q.front().second;
        q.pop();
        
        dp[u] = sum[lvl - 1] - dp[fa[u]];
        if (lvl == sum.size() - 1) {
            sum.back() += dp[u];
            sum.back() %= MOD;
        } else {
            sum.push_back(dp[u]);
        }
        for (auto v : adj[u]) {
            q.push({v, lvl + 1});
        }
    }

    LL res = 0;
    for (auto x : dp) {
        res += x;
        res %= MOD;
    }
    cout << (res + MOD) % MOD << '\n';
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