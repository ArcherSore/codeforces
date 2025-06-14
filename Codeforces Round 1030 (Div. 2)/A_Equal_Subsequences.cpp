#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            cout << 0;
        }
        cout << '\n';
        return;
    }
    if (n - m == 0) {
        for (int i = 0; i < n; i++) {
            cout << 1;
        }
        cout << '\n';
        return;
    }

    cout << 1;
    n--, m--;
    for (int i = 0; i < n - m - 1; i++) {
        cout << 0;
    }
    for (int i = 0; i < m; i++) {
        cout << 1;
    }
    cout << 0 << '\n';
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