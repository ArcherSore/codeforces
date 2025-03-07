#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, m, r, c;
    cin >> n >> m >> r >> c;

    LL res = 0;
    res += m - c;
    res += (2 * m - 1) * (n - r); 
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