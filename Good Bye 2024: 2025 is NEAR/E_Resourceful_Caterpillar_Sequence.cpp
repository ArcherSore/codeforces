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
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int leaf = 0, not_adj_leaf = 0;
    auto calculate = [&](auto &self, int fa, int u) -> void {
        if (G[u].size() == 1) {
            leaf += 1;
        }
        int flag = 1;
        if (fa != -1 && G[fa].size() == 1) {
            flag = 0;
        }
        for (auto v : G[u]) {
            if (v == fa) {
                continue;
            }
            if (G[v].size() == 1) {
                flag = 0;
            }
            self(self, u, v);
        }
        not_adj_leaf += flag;
    };
    calculate(calculate, -1, 0);
    not_adj_leaf -= leaf;
    // cout << leaf << ' ' << not_adj_leaf << '\n';

    LL ans = 1LL * leaf * (n - leaf);
    auto dfs = [&](auto &self, int fa, int u) -> void {
        int cnt = 0, flag = 0;
        for (auto v : G[u]) {
            if (v != -1 && G[v].size() != 1) {
                cnt += 1;
            }
            if (v != -1 && G[v].size() == 1) {
                flag = 1;
            }

            if (v == fa) {
                continue;
            }
            self(self, u, v);
        }
        if (flag) {
            ans += 1LL * max(cnt - 1, 0) * not_adj_leaf;
        }
    };
    dfs(dfs, -1, 0);
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