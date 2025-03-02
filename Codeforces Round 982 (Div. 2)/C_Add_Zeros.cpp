#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] += i;
    }
    map<LL, vector<LL>> mp;
    for (int i = 0; i < n; i++) {
        mp[v[i]].push_back(i);
    }
    
    vector<LL> vis(n);
    auto dfs = [&](auto &self, LL sz) -> LL {
        if (mp.find(sz) == mp.end()) {
            return 0;
        }
        LL mx = 0;
        for (auto i : mp[sz]) {
            if (i == 0) {
                continue;
            }
            if (!vis[i]) {
                vis[i] = self(self, sz + i) + i;
            }
            mx = max(mx, vis[i]);
        }
        return mx;
    };
    LL res = n + dfs(dfs, n);
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