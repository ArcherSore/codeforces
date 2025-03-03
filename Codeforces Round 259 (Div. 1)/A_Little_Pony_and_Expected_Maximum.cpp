#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int m, n;
    cin >> m >> n;
    double res = 0;
    for (int i = 1; i <= m; i++) {
        res += 1.0 * i * (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n));
    }
    cout << fixed << setprecision(5) << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}