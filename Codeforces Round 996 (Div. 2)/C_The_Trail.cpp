//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    string dir;
    cin >> dir;

    vector<vector<LL>> grid(n, vector<LL>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<LL> sumx(n), sumy(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sumx[i] += grid[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sumy[j] += grid[i][j];
        }
    }

    int x = 0, y = 0;
    for (char c : dir) {
        if (c == 'D') {
            grid[x][y] = -sumx[x];
            sumy[y] += grid[x][y];
            x += 1;
        } else {
            grid[x][y] = -sumy[y];
            sumx[x] += grid[x][y];
            y += 1;
        }
    }
    grid[x][y] = -sumx[n - 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}