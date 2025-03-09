#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

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
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0, cnt_ = 0;
    int avai = 0;
    auto dfs = [&](auto &self, int u, int fa) -> void {
        if (adj[u].size() == 1 && u != 0) {
            if (s[u] == '0') {
                cnt0++;
            } else if (s[u] == '1') {
                cnt1++;
            } else {
                cnt_++;
            }
        }
        if (adj[u].size() > 1 && u != 0 && s[u] == '?') {
            avai++;
        }
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);
    int res = 0;
    if (s[0] == '?') {
        res = max(cnt0, cnt1) + cnt_ / 2;
        if (avai % 2) {
            res = max(res, min(cnt0, cnt1) + (cnt_ + 1) / 2);
        }
    } else {
        if (s[0] == '0') {
            res = cnt1 + (cnt_ + 1) / 2;
        } else {
            res = cnt0 + (cnt_ + 1) / 2;
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