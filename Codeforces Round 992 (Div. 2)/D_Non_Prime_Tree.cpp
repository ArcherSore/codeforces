#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct State {
    int u, dep;
    int fa;
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int l = 2, r = 2 * n;
    vector<int> res(n);
    
    int cnt = 0;
    queue<State> q;
    vector<int> vis(n);
    q.push({0, 0, -1});
    while (!q.empty()) {
        auto [u, dep, fa] = q.front();
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        
        cnt += 1;
        if (cnt == n) {
            if (res[fa] != 2 * n) {
                res[u] = res[fa] + 1;
            } else {
                res[u] = res[fa] - 1;
            }
            break;
        }

        if (dep & 1) {
            res[u] = r;
            r -= 2;
        } else {
            res[u] = l;
            l += 2;
        }

        for (auto v : g[u]) {
            q.push({v, dep + 1, u});
        }
    }

    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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