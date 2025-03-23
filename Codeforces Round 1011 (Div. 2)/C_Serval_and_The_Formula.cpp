#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL x, y;
    cin >> x >> y;
    if (x == y) {
        cout << -1 << '\n';
        return;
    }
    if ((x & y) == 0) {
        cout << 0 << '\n';
        return;
    }

    LL mx = max(x, y);
    int k = __lg(mx) + 1;
    LL res = (1LL << k) - mx;
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