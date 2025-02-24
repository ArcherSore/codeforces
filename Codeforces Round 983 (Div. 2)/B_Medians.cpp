#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n' << 1 << '\n';
        return;
    }
    if (k == 1 || k == n) {
        cout << -1 << '\n';
        return;
    }
    if (k & 1) {
        cout << 3 << '\n';
        cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
    } else {
        cout << 3 << '\n';
        cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
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