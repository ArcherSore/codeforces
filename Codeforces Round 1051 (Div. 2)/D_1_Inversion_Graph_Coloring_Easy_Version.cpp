#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll mod = 1e9 + 7;

struct Fenwick {
    int n;
    vector<ll> a;
    Fenwick() {}
    Fenwick(int _n = 0) {
        init(_n);
    }
    void init(int _n) {
        n = _n;
        a.assign(n, 0ll);
    }
    void add(int x, ll v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = (a[i - 1] + v) % mod;
        }
    }
    ll query(int x) {
        ll res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            res = (res + a[i - 1]) % mod;
        }
        return res;
    }
    ll rangeQuery(int l, int r) {
        return (query(r) - query(l) + mod) % mod;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    vector<Fenwick> row(n, Fenwick(n));
    vector<Fenwick> col(n, Fenwick(n));
    for (int i = 0; i < n; i++) {
        vector<ll> r(n), c(n);
        for (int j = a[i] + 1; j < n; j++) {
            r[j] = row[j].rangeQuery(0, a[i] + 1);
        }
        for (int k = 0; k <= a[i]; k++) {
            c[k] = col[k].rangeQuery(k, a[i] + 1);
        }

        for (int j = a[i] + 1; j < n; j++) {
            row[j].add(a[i], r[j]);
            col[a[i]].add(j, r[j]);
        }
        for (int k = 0; k <= a[i]; k++) {
            col[k].add(a[i], c[k]);
            row[a[i]].add(k, c[k]);
        }
        row[a[i]].add(0, 1);
        col[0].add(a[i], 1);
    }
    ll res = 1;
    for (int i = 0; i < n; i++) {
        res = (res + row[i].rangeQuery(0, n)) % mod;
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