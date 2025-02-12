#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int> (n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int mx = -INF, res = 0;
    for (int i = 0; i < n; i++) {
        if (v[0][i] >= v[1][i]) {
            res += v[0][i];
            mx = max(mx, v[1][i]);
        } else {
            res += v[1][i];
            mx = max(mx, v[0][i]);
        }
    }
    res += mx;
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