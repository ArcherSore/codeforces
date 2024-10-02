// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<LL, int>;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<LL> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<vector<LL>> dp(n, vector<LL> (2));
    auto dfs = [&](auto &self, int u, int fa) -> void {
        dp[u][0] = 0;
        dp[u][1] = A[u];
        for (auto v : G[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
    };

    dfs(dfs, 0, -1);

    LL ans = max(dp[0][1], dp[0][0]);

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