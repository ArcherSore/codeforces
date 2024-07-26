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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char> (m));
    vector<vector<char>> b(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    int row1 = 0, row2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row1 += a[i][j] - '0';
            row2 += b[i][j] - '0'; 
        }
        if (row1 % 3 != row2 % 3) {
            cout << "NO\n";
            return;
        }
    }
    int col1 = 0, col2 = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            col1 += a[i][j] - '0';
            col2 += b[i][j] - '0';
        }
        if (col1 % 3 != col2 % 3) {
            cout << "NO\n";
            return;
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