#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<LL> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> adj(n);
    vector<int> depth(n);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        u--;
        adj[u].push_back(i);
        depth[i] = depth[u] + 1;
    }

    vector<LL> b(n);
    for (int i = 0; i < n; i++) {
        if (adj[i].empty()) {
            b[i] = INF;
        } else {
            LL tot = 0;
            for (auto v : adj[i]) {
                tot += p[v];
            }
            b[i] = tot - p[i];
        }
    }

    LL res = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] >= 0) {
            continue;
        }
        queue<int> q;
        q.push(i);
        while (!q.empty() && b[i] < 0) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                if (b[v] < 0) {
                    continue;
                }
                LL avai = min(-b[i], b[v]);
                b[i] += avai;
                b[v] -= avai;
                res += avai * (depth[v] - depth[i]);
                q.push(v);
            }
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