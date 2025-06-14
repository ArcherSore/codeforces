#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int k = 2 * n - 1;
    cout << k << '\n';
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << i << ' ' << n << '\n';
    }
    for (int i = 2; i <= n; i++) {
        cout << i << ' ' << 1 << ' ' << i - 1 << '\n';
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