#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, p, k;
    cin >> n >> k >> p;
    k = abs(k);

    int res = ceil(1.0 * k / p);
    if (res > n) {
        cout << -1 << '\n';
    } else {
        cout << res << '\n';
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