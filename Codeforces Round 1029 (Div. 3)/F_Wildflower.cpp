#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        x >>= 1;
    }
    return res;
}

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

    int cnt = 0, node = -1;
    for (int i = 0; i < n; i++) {
        auto v = adj[i];
        if (v.size() == 3 || i == 0 && v.size() == 2) {
            cnt++;
            node = i;
        }
        if (i == 0 && v.size() > 2 || v.size() > 3 || cnt > 1) {
            cout << 0 << '\n';
            return;
        }
    }

    int flag = 0;
    int c1 = 0, c2 = 0, c3 = 0;
    auto dfs = [&](auto &self, int u, int fa, int dir) -> void {
        if (!flag) {
            c1++;
        } else if (dir == 0) {
            c2++;
        } else {
            c3++;
        }
        if (u == node) {
            flag = 1;
        }
        int i = 0;
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            if (i == 0) {
                self(self, v, u, dir);            
            } else {
                self(self, v, u, 1 - dir);
            }
            i++;
        }
    };
    dfs(dfs, 0, -1, 0);
    // cout << c1 << ' ' << c2 << ' ' << c3 << '\n';

    int d = abs(c2 - c3);
    LL res = 1;
    if (d == 0) {
        if (c2 == 0) {
            res = fpow(2, c1);
        } else {
            res = fpow(2, c1) * 2 % MOD;
        }
    } else {
        res = fpow(2, c1) * ((fpow(2, d - 1) + fpow(2, d)) % MOD) % MOD;
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