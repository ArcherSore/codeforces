#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int cnt = 0, id = -1;
    vector<int> pos(n, -1);
    vector<vector<string>> c(m, vector<string> (n));
    for (int i = 0; i < m; i++) {
        int match = 0;
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            if (c[i][j] == a[j]) {
                pos[j] = i;
                match++;
            }
        }
        if (match > cnt) {
            cnt = match;
            id = i;
        }
    }
    if (count(pos.begin(), pos.end(), -1) > 0) {
        cout << -1 << '\n';
        return;
    }

    // cout << cnt << ' ';
    int res = n + 2 * (n - cnt);
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