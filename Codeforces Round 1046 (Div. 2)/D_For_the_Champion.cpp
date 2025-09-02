#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll inf = 1e9;

void query(char d, ll k) {
    cout << "? " << d << ' ' << k << endl;
    ll x;
    cin >> x;
}

void query(char d, ll k, ll &x) {
    cout << "? " << d << ' ' << k << endl;
    cin >> x;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll mn1 = 4 * inf, mn2 = 4 * inf;
    for (int i = 0; i < n; i++) {
        mn1 = min(mn1, x[i] + y[i]);
        mn2 = min(mn2, y[i] - x[i]);
    }
    ll res1, res2;
    query('L', inf);
    query('L', inf);
    query('D', inf);
    query('D', inf, res1);
    res1 = -(res1 - 4 * inf - mn1);
    query('R', inf);
    query('R', inf);
    query('R', inf);
    query('R', inf, res2);
    res2 = res2 -  mn2 - 4 * inf;

    cout << "! " << (res1 + res2) / 2 << ' ' << (res1 - res2) / 2 << endl;
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