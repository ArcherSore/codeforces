#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int col = 0, row = 0;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < m; j++) {
            res ^= (v[i][j] - '0');
        }
        if (res) row++;
    }
    for (int j = 0; j < m; j++) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= (v[i][j] - '0');
        }
        if (res) col++;
    }
    cout << max(col, row) << '\n';
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