#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

ll fpow(ll a, ll x) {
    ll res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return fpow(x, mod - 2);
}

ll mul(ll a, ll b) {
    return a * b % mod;
}

ll sub(ll a, ll b) {
    return ((a - b) % mod + mod) % mod;
}

ll calc(int n, int m) {
    ll res = 1, mul = 26;
    for (int i = 1; i <= m; i++) {
        if (mul > n) {
            res += n;
        } else {
            res += mul;
            mul *= 26;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    ll mx = calc(n, m) % mod;

    ll E = 1;
    for (int i = 1; i <= m; i++) {
        ll nE = mul(fpow(26, i), sub(1, fpow(sub(1, inv(fpow(26, i))), n)));
        E = (E + nE) % mod;
    }

    cout << mx << ' ' << E;

    return 0;
}