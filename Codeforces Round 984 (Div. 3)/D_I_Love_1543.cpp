#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < min(n, m) / 2; i++) {
        string s;
        int x = i, y = i;
        while (y + 1 < m - i) {
            s.push_back(g[x][y]);
            y++;
        }
        while (x + 1 < n - i) {
            s.push_back(g[x][y]);
            x++;
        }
        while (y - 1 >= i) {
            s.push_back(g[x][y]);
            y--;
        }
        while (x - 1 >= i) {
            s.push_back(g[x][y]);
            x--;
        }
        // cout << s << '\n';
        s += s;
        int cnt = 0;
        for (int i = 0; i < s.size() - 3; i++) {
            string t = s.substr(i, 4);
            if (t == "1543") {
                cnt++;
            }
        }
        cnt = (cnt + 1) / 2;
        res += cnt;
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