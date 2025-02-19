#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    map<int, int> cost;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cost.find(g[i][j]) == cost.end()){
                cost[g[i][j]] = 1;
            }

            if (j + 1 < m && g[i][j + 1] == g[i][j]){
                cost[g[i][j]] = 2;
            }
            if (i + 1 < n && g[i + 1][j] == g[i][j]){
                cost[g[i][j]] = 2;
            }
        }
    }

    int tot = 0;
    int save = 0;
    for (auto x : cost) {
        tot += x.second;
        save = max(save, x.second);
    }

    int res = tot - save;
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