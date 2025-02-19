#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    LL f1 = 0, f2 = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            f1 += 1;
        } else if (v[i] == 2) {
            f2 = (f2 * 2 + f1) % MOD;
        } else {
            res += f2;
            res %= MOD;
        }
    }
    cout << res % MOD << '\n';
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