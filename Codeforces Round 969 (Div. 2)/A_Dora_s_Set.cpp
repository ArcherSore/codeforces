#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int l, r;
    cin >> l >> r;
    if (l % 2 == 0) {
        l += 1;
    }
    int res = 0;
    for (int i = l + 2; i <= r; i += 4) {
        res += 1;
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