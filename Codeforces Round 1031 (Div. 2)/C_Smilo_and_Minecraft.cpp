#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    vector<vector<char>> g(n + 1, vector<char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'g') {
                res++;
            }
        }
    }
    vector<vector<int>> pre(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (g[i][j] == 'g');
        }
    }
    int cnt = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != '.') {
                continue;
            }
            int x1 = max(1, i - k + 1), y1 = max(1, j - k + 1);
            int x2 = min(n, i + k - 1), y2 = min(m, j + k - 1);
            cnt = min(cnt, pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1]);
        }
    }
    res -= cnt;
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