#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end(), greater<> ());

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += max(0LL, m - i) * a[i];
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