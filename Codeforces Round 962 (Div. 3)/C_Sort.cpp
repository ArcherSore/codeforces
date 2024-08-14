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
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    s = ' ' + s, t = ' ' + t;
    vector<vector<int>> a(n + 1, vector<int> (26));
    vector<vector<int>> b(n + 1, vector<int> (26));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            a[i][j] = a[i - 1][j] + (s[i] - 'a' == j);
            b[i][j] = b[i - 1][j] + (t[i] - 'a' == j);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int c1 = a[r][i] - a[l - 1][i];
            int c2 = b[r][i] - b[l - 1][i];
            ans += abs(c1 - c2);
        }
        cout << ans / 2 << '\n';
    }
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