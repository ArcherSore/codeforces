#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int a = min(x, y);
    cout << 0 << ' ' << 0 << ' ' << a << ' ' << a << '\n';
    cout << 0 << ' ' << a << ' ' << a << ' ' << 0 << '\n';
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