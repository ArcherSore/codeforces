#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(b.begin() + 1, b.end());
    
    ll res = 0;
    for (int d = 1; d <= 500; d++) {
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++) {
            c[i] = upper_bound(a.begin() + 1, a.end(), b[i] - d) - a.begin() - 1;
            // cerr << c[i] << ' ';
        }
        // cerr << '\n';
        vector<vector<ll>> dp(m + 1, vector<ll> (n + 1));
        for (int i = 1; i <= m; i++) {
            dp[i - 1][0] = 1;
            for (int j = 1; j <= min(i, n); j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * max(0, c[i] - j + 1) % mod) % mod;
            }
        }

        ll sum = 0;
        for (int j = 1; j <= min(m, n); j++) {
            sum = (sum + dp[m][j]) % mod;
        }
        // cerr << sum << '\n';
        res = (res + sum) % mod;
    }
    cout << res << '\n';

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }

    return 0;
}