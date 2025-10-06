#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 2e5;
const ll mod = 998244353;

vector<ll> f(N + 1), invf(N + 1);

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

void init() {
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    invf[N] = fpow(f[N], mod - 2);
    for (int i = N - 1; i >= 0; i--) {
        invf[i] = invf[i + 1] * (i + 1) % mod;
    }
}

ll C(ll n, ll m) {
    if (n < m || m < 0) {
        return 0;
    }
    return f[n] * invf[m] % mod * invf[n - m] % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    ll tot = 0;
    for (int i = 0; i <= (n - 1) / 2; i++) {
        tot += a[i];
        if (tot < min(2 * (i + 1), n)) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = (n - 1) / 2 + 1; i < n; i++) {
        if (a[i] != 0) {
            cout << 0 << '\n';
            return;
        }
    }

    ll need = 0, res = 1;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        need += 2 - (i == n - i - 1);
        res *= C(need, a[i]);
        // cerr << need << ' ' << a[i] << ' ' << res << '\n';
        res %= mod;
        need -= a[i];
    }
    // cerr << '\n';
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}