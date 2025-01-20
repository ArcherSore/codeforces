// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e18;

void solve() {
    LL n, m, p;
    cin >> n >> m >> p;
    vector<vector<LL>> a(n, vector<LL> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<vector<LL>>> f(n, vector<vector<LL>> (m, vector<LL> (m, INF)));
    vector<vector<LL>> mn(n, vector<LL> (m, INF));
    for (int j = 0; j < m; j++) {
        f[0][j][j % m] = j * p + a[0][j % m];
        mn[0][0] = min(mn[0][0], f[0][j][j % m]);
        for (int k = 1; k < m; k++) {
            int t = (k + j) % m;
            f[0][j][t] = f[0][j][(t - 1 + m) % m] + a[0][t];
            mn[0][k] = min(mn[0][k], f[0][j][t]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i][j][j % m] = min(f[i][j][j % m], mn[i - 1][0] + j * p + a[i][j % m]);
            mn[i][0] = min(mn[i][0], f[i][j][j % m]);
            for (int k = 1; k < m; k++) {
                int t = (k + j) % m;
                f[i][j][t] = min({f[i][j][t], mn[i - 1][k] + j * p + a[i][t], f[i][j][(t - 1 + m) % m] + a[i][t]});
                mn[i][k] = min(mn[i][k], f[i][j][t]);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << mn[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << mn[n - 1][m - 1] << '\n';
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