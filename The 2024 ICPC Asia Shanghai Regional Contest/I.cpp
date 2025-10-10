#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<ll> ());
    while (!a.empty() && a.back() == 0) {
        a.pop_back();
    }
    n = a.size();

    if (n == 0) {
        cout << 0 << '\n';
        return;
    }

    ll res = a[0] % mod, cnt = (n - 1) / (k - 1) * (k - 1);
    for (int i = 1; i <= cnt; i++) {
        res = res * a[i] % mod;
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