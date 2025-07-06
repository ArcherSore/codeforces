#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b) {
        if (a == b + 1 && (a & 1)) {
            cout << y << '\n';
        } else {
            cout << -1 << '\n';
        }
    } else {
        if (x <= y) {
            cout << 1LL * (b - a) * x << '\n';
        } else {
            if ((b - a) % 2) {
                cout << 1LL * (b - a) / 2 * (x + y) + (a % 2 ? x : y) << '\n';
            } else {
                cout << 1LL * (b - a) / 2 * (x + y) << '\n';
            }
        }
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