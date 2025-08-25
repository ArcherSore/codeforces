#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<ll, 3>> seg(n);
    for (int i = 0; i < n; i++) {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        l--, r--;
        seg[i] = {l, r, p * inv(q) % mod};
    }
    sort(seg.begin(), seg.end(), [](const auto &a, const auto &b) {
        if (a[1] != b[1]) {
            return a[1] > b[1];
        }
        return a[0] > b[0];
    });

    ll np = 1; // the possibility of choosing no segment
    for (auto &e : seg) {
        np = np * ((1 - e[2] + mod) % mod) % mod;
    }

    vector<ll> f(m + 1);
    f[m] = np;
    for (auto &[l, r, p] : seg) {
        // f[l] = f[r + 1] / (1 - p) * p
        f[l] = (f[l] + (f[r + 1] * inv((1 - p + mod) % mod) % mod) * p % mod) % mod;
    }
    cout << f[0] << '\n';
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