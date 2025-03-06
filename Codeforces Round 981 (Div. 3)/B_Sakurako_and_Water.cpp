#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int mx1 = 0, mx2 = 0;
        for (int j = i; j < n; j++) {
            if (a[j][j - i] < 0) {
                mx1 = max(mx1, -a[j][j - i]);
            }
            if (i && a[j - i][j] < 0) {
                mx2 = max(mx2, -a[j - i][j]);
            }
        }
        res += mx1 + mx2;
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