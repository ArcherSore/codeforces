#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    int tot = 0;
    for (auto &x : a) {
        cin >> x;
        tot += x;
    }
    sort(a.begin(), a.end());
    
    vector<LL> dp(tot + 1, 0);
    dp[0] = 1;

    LL res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            res = (res + dp[j] * max((j + a[i] + 1) / 2, a[i]) % MOD) % MOD;
        }
        sum += a[i];
        for (int j = sum; j >= a[i]; j--) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }

    cout << res << '\n';
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