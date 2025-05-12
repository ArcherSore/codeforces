#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<PII> v(n), ori(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    ori = v;
    sort(v.begin(), v.end(), greater<PII>());
    
    int res = 0;
    vector<int> vis(n);
    auto dfs = [&](auto &self, int u) -> void {
        if (vis[u]) {
            return;
        }
        vis[u] = 1;
        if (u && ori[u].first >= ori[u - 1].first) {
            self(self, u - 1);
        }
        if (u < n - 1 && ori[u].first >= ori[u + 1].first) {
            self(self, u + 1);
        }
    };
    for (auto [x, id] : v) {
        if (vis[id]) {
            continue;
        }
        res++;
        dfs(dfs, id);
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