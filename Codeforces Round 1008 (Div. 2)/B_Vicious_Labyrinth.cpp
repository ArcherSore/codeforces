#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k % 2) {
        for (int i = 1; i < n; i++) {
            cout << n << ' ';
        }
        cout << n - 1 << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            if (i == n - 1) {
                cout << n << ' ';
            } else {
                cout << n - 1 << ' ';
            }
        }
        cout << '\n';
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