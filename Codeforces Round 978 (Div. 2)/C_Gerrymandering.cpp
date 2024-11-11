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
    vector<vector<char>> grid(2, vector<char> (n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    auto check = [&](PII x1, PII x2, PII x3) -> bool {
        int cnt = 0;
        if (x1.second < n && grid[x1.first][x1.second] == 'A') cnt++;
        if (x2.second < n && grid[x2.first][x2.second] == 'A') cnt++;
        if (x3.second < n && grid[x3.first][x3.second] == 'A') cnt++;
        return cnt >= 2;
    };

    vector<vector<int>> f(2, vector<int> (n + 3));
    for (int j = 0; j < n; j++) {
        if (j % 3 == 0) {
            f[0][j + 1] = max(f[0][j + 1], max(f[0][j], f[1][j]) + check({0, j}, {1, j}, {1, j + 1}));
            f[1][j + 1] = max(f[1][j + 1], max(f[0][j], f[1][j]) + check({0, j}, {1, j}, {0, j + 1}));
            f[0][j + 3] = max(f[0][j + 3], max(f[0][j], f[1][j]) + check({0, j}, {0, j + 1}, {0, j + 2}) + check({1, j}, {1, j + 1}, {1, j + 2}));
            f[1][j + 3] = max(f[1][j + 3], f[0][j + 3]);
        }
        if (j % 3 == 1) {
            f[0][j + 2] = max(f[0][j + 2], f[0][j] + check({0, j}, {0, j + 1}, {1, j + 1}));
            f[1][j + 2] = max(f[1][j + 2], f[0][j + 2]);
            f[0][j + 2] = max(f[0][j + 2], f[1][j] + check({1, j}, {0, j + 1}, {1, j + 1}));
            f[1][j + 2] = max(f[1][j + 2], f[0][j + 2]);
            f[0][j + 3] = max(f[0][j + 3], f[0][j] + check({0, j}, {0, j + 1}, {0, j + 2}) + check({1, j + 1}, {1, j + 2}, {1, j + 3}));
            f[1][j + 3] = max(f[1][j + 3], f[1][j] + check({1, j}, {1, j + 1}, {1, j + 2}) + check({0, j + 1}, {0, j + 2}, {0, j + 3}));
        }
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < n + 3; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n + 3; j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << '\n';
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