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

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char> (n));
    vector<vector<int>> vis(n, vector<int> (n));
    vector<int> col(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int cnt = n;
    while (cnt--) {
        int res;
        for (int i = 0; i < g.size(); i++) {
            if (col[i]) {
                continue;
            }
            bool ok = true;
            for (int j = 0; j < i; j++) {
                if (vis[i][j]) {
                    continue;
                }
                if (g[i][j] == '1') {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;;
            }
            for (int j = i + 1; j < g.size(); j++) {
                if (vis[i][j]) {
                    continue;
                }
                if (g[i][j] == '0') {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;;
            }
            res = i;
            cout << res + 1 << ' ';

            col[res] = 1;
            for (int k = 0; k < n; k++) {
                g[k][res] = 1;
                g[res][k] = 1;
            }
        }
    }
    cout << '\n';
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