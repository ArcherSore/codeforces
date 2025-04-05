#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}

LL inv(int x) {
    return fpow(x, MOD - 2);
}

LL fac(int x) {
    LL res = 1;
    while (x > 1) {
        res = res * x % MOD;
        x--;
    }
    return res;
}

void solve() {
    int tot = 0;
    vector<int> c(26);
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
        tot += c[i];
    }
    int odd = (tot + 1) / 2, even = tot / 2;
    vector<LL> dp(odd + 1);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        if (c[i] == 0) {
            continue;
        }
        for (int j = odd; j >= c[i]; j--) {
            dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
        }
    }
    if (dp[odd] == 0) {
        cout << 0 << '\n';
        return;
    }
    LL res = dp[odd];
    // cout << res << ' ';
    res = (res * fac(odd) % MOD) * fac(even) % MOD;
    for (int i = 0; i < 26; i++) {
        if (c[i] == 0) {
            continue;
        }
        res = (res * inv(fac(c[i]))) % MOD;
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