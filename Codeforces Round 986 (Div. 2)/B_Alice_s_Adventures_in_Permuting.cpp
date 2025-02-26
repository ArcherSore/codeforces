#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, b, c;
    cin >> n >> b >> c;
    if (b == 0) {
        if (c >= n) {
            cout << n << '\n';
        } else if (c >= n - 2) {
            cout << n - 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    if (c >= n) {
        cout << n << '\n';
        return;
    }
    LL res = (LL)(ceil(1.0 * (n - c) / b));
    cout << n - res << '\n';
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