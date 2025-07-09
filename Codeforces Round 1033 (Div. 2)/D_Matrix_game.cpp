#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;
const int N = 1e5;

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

vector<LL> fac;

void init() {
    fac.assign(N + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

LL C(LL n, LL a) {
    LL res = 1;
    for (int i = n; i >= n - a + 1; i--) {
        res = (res * i) % MOD;
    }
    res = res * fpow(fac[a], MOD - 2) % MOD;
    return res;
}

void solve() {
    LL a, b, k;
    cin >> a >> b >> k;
    LL n = (k * (a - 1) % MOD + 1) % MOD;
    LL m = ((k * (b - 1) % MOD) * C(n, a) % MOD + 1) % MOD;
    cout << n << ' ' << m << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    init();

    while (T--) {
        solve();
    }

    return 0;
}