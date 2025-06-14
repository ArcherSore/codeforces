#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, k, q;
    cin >> n >> k;
    vector<LL> p(n);
    for (auto &x : p) {
        cin >> x;
    }
    vector<LL> d(n);
    for (auto &x : d) {
        cin >> x;
    }
    cin >> q;
    vector<array<LL, 2>> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end(), [](const auto &a1, const auto &a2) {
        return a1[0] > a2[0];
    });
    
    map<LL, int> mp1, mp2; // the fir pos mp[x] appear
    vector<LL> f1(n), f2(n);
    for (int i = 0; i < n; i++) {
        f1[i] = (p[i] - d[i] + k) % k;
        mp1[f1[i]] = -1;
        f2[i] = (p[i] + d[i] + k) % k;
        mp2[f2[i]] = -1;
    }

    vector<int> adj(2 * n);
    for (int i = n - 1; i >= 0; i--) {
        adj[i] = mp1[f1[i]];
        mp1[f1[i]] = i + n;
    }
    for (int i = 0; i < n; i++) {
        adj[i + n] = mp2[f2[i]];
        mp2[f2[i]] = i;
    }

    vector<int> vis(n + n), exit(n + n);
    auto dfs = [&](auto &self, int u) -> bool {
        if (u == -1) {
            return true;
        }
        if (vis[u]) {
            return exit[u];
        }
        vis[u] = 1;
        exit[u] = self(self, adj[u]);
        return exit[u];
    };
    for (int i = 0; i < n + n; i++) {
        if (!vis[i]) {
            dfs(dfs, i);
        }
    }

    vector<int> res(q);
    int pos = n - 1;
    mp1.clear();
    for (auto [st, i] : a) {
        while (pos >= 0 && p[pos] >= st) {
            mp1[f1[pos]] = pos;
            pos--;
        }
        if (mp1.find(st % k) != mp1.end()) {
            res[i] = exit[mp1[st % k] + n];
        } else {
            res[i] = 1;
        }
    }
    for (auto x : res) {
        cout << (x ? "YES\n" : "NO\n");
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