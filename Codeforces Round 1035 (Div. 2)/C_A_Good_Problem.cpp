#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n & 1) {
        cout << l << '\n';
        return;
    }
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }
    if (n >= 4) {
        LL res = 1LL << __lg(l) + 1;
        if (res > r) {
            cout << -1 << '\n';
            return;
        }
        if (k <= n - 2) {
            cout << l << '\n';
        } else {
            cout << res << '\n';
        }
    }
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