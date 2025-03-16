#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

struct Comb {
    int n;
    vector<LL> fac, invfac;

    Comb(int _n) : n(_n) {
        fac.resize(n + 1);
        invfac.resize(n + 1);
        init();
    }

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

    void init() {
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = (fac[i - 1] * i) % MOD;
        }
        invfac[n] = fpow(fac[n], MOD - 2);
        for (int i = n; i >= 1; i--) {
            invfac[i - 1] = (invfac[i] * i) % MOD;
        }
    }

    LL C(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        return ((fac[n] * invfac[k]) % MOD) * invfac[n - k] % MOD;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
    }

    Comb comb(n);

    LL res = 0;
    for (int i = max(k - cnt0, (k + 1) / 2); i <= min(k, n); i++) {
        res += comb.C(cnt1, i) * comb.C(cnt0, k - i);
        res %= MOD;
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