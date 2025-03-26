#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &s : g) {
        cin >> s;
    } 
    vector<vector<bool>> vis(n, vector<bool> (m));
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m && g[i][j] == '1') {
            vis[i][j] = 1;
            j++;
        }
    }
    for (int j = 0; j < m; j++) {
        int i = 0;
        while (i < n && g[i][j] == '1') {
            vis[i][j] = 1;
            i++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1' && !vis[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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