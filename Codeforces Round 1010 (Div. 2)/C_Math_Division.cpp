#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

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

const LL inv2 = fpow(2, MOD - 2);

void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    vector<LL> f(n), g(n);

    int cnt1 = 1, last = 0;
    for (int i = 1; i < n; i++) {
        last = cnt1;
        if (x[i] == '1') {
            cnt1++;
        } else {
            cnt1 = 0;
        }

        if (x[i] == '1') {
            int t = cnt1;
            // assert(i - t < 0);
            f[i] = g[i] = ((f[i - 1] + 1) * inv2 % MOD + ((i - t >= 0 ? g[i - t] : 0) + t) * inv2 % MOD) % MOD;
        } else {
            int t = last + 1;
            // assert(i - t < 0);
            f[i] = (f[i - 1] + 1) % MOD;
            g[i] = ((f[i - 1] + 1) * inv2 % MOD + ((i - t >= 0 ? g[i - t] : 0) + t) * inv2 % MOD) % MOD;
        }
    }
    cout << f[n - 1] << '\n';
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