#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n), a(m);
    vector<int> mp(n + 1); // p_i->i
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        mp[p[i]] = i;
    }
    for (auto &x : a) {
        cin >> x;
    }

    const int LOG = __lg(n) + 1;
    vector<vector<int>> jump(m, vector<int> (LOG));
    vector<int> app(n + 1, INF);
    for (int i = m - 1; i >= 0; i--) {
        int j = mp[a[i]];
        jump[i][0] = app[p[(j + 1) % n]];
        app[a[i]] = i;
    }
    for (int k = 0; k < LOG - 1; k++) {
        for (int i = 0; i < m; i++) {
            if (jump[i][k] == INF) {
                jump[i][k + 1] = INF;
            } else {
                jump[i][k + 1] = jump[jump[i][k]][k];
            }
        }
    }

    const int d = n - 1;
    vector<int> nearest(m);
    for (int i = 0; i < m; i++) {
        int u = i;
        for (int k = LOG - 1; k >= 0; k--) {
            if ((d >> k) & 1) {
                u = jump[u][k];
                if (u == INF) {
                    break;
                }
            }
        }
        nearest[i] = u;
    }

    vector<int> dp(m);
    dp[m - 1] = nearest[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        dp[i] = min(dp[i + 1], nearest[i]);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (dp[x] <= y) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}