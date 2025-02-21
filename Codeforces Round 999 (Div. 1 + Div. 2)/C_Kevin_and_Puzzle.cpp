#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    vector<LL> h(n), l(n);
    h[0] = (v[0] == 0);
    l[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1] == v[i]) {
            h[i + 1]  += h[i];
        }
        l[i + 1] += h[i];
        if (i) {
            if (v[i + 1] == v[i - 1] + 1) {
                h[i + 1] += l[i];
            }
        } else {
            if (v[i + 1] == 1) {
                h[i + 1] += l[i];
            }
        }
        h[i + 1] %= MOD;
        l[i + 1] %= MOD;
    }
    cout << (h[n - 1] + l[n - 1]) % MOD << '\n';
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