#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << '\n';
        return;
    }
    int bitwidth = __lg(k) + 1;
    if (k == (1 << bitwidth) - 1) {
        cout << k << ' ' << 0 << ' ';
        k = 0;
    } else {
        int t = (1 << bitwidth - 1) - 1;
        cout << t << ' ' << k - t << ' ';
        k = 0;
    }
    for (int i = 2; i < n; i++) {
        cout << k << " ";
    }
    cout << '\n';
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