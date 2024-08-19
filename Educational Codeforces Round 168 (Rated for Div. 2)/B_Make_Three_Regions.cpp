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
    vector<vector<char>> cell(2, vector<char> (n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cell[i][j];
        }
    }
    int ans = 0;
    for (int j = 2; j < n; j++) {
        for (int i = 0; i < 2; i++) {
            if (cell[i][j] == 'x' && cell[i][j - 1] == '.' && cell[i][j - 2] == 'x' && cell[i ^ 1][j - 1] == '.' && cell[i ^ 1][j] == '.' && cell[i ^ 1][j - 2] == '.') {
                ans++;
            }
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