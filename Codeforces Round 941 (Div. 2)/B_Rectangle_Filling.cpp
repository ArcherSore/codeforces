#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    if (v[0][0] == v[n - 1][m - 1] || v[0][m - 1] == v[n - 1][0]) {
        cout << "YES\n";
        return;
    }
    if (v[0][0] == v[0][m - 1]) {
        for (int j = 0; j < m; j++) {
            if (v[n - 1][j] == v[0][0] || v[0][j] == v[n - 1][0]) {
                cout << "YES\n";
                return;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (v[i][m - 1] == v[0][0] || v[i][0] == v[0][m - 1]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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