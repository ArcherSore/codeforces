#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            continue;
        }
        if (a[i] > n) {
            cout << 0 << '\n';
            return;
        } else if (a[i] == i || a[i] == 0) {
            if (vis[i]) {
                cout << 0 << '\n';
                return;
            }
            vis[i] = 1;
        } else {
            if (a[a[i]] != -1 && a[a[i]] != i) {
                cout << 0 << '\n';
                return;
            }
            a[a[i]] = i;
            vis[i] = vis[a[i]] = 1;
        }
    }
    int m = count(a.begin() + 1, a.end(), -1) + 1;
    if (m == 1) {
        cout << 1 << '\n';
        return;
    }
    bool flag = (a[n] == -1);
    vector<ll> dp(m);
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < m; i++) {
        dp[i] = (2 * dp[i - 1] % mod + (i - 1) * dp[i - 2] % mod) % mod;
    }
    ll res = dp[m - 1];
    if (flag) {
        if (m > 2) {
            res = (res - dp[m - 2] + mod) % mod;
        } else {
            res = (res - 1 + mod) % mod;
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