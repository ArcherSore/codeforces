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
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;

    int l = b - a - 1, r = n - l - 2;
    vector<int> ans(n);
    if (l % 2 && r % 2) {
        ans[a] = 0, ans[b] = 2;
        int x = (a - 1 + n) % n, y = (a + 1) % n;
        int fill = 1;
        while (x != b) {
            ans[x] = fill;
            fill = 1 - fill;
            x = (x - 1 + n) % n;
        }
        fill = 1;
        while (y != b) {
            ans[y] = fill;
            fill = 1 - fill;
            y = (y + 1) % n;
        }
    } else if (l % 2 == 0 && r % 2 == 0) {
        for (int i = 0; i < n; i++) {
            ans[i] = i & 1;
        }
    } else {
        ans[a] = 0, ans[b] = 2;
        int x = (a - 1 + n) % n, y = (a + 1) % n;
        int fill = 1;
        while (x != b) {
            ans[x] = fill;
            fill = 1 - fill;
            x = (x - 1 + n) % n;
        }
        fill = 1;
        while (y != b) {
            ans[y] = fill;
            fill = 1 - fill;
            y = (y + 1) % n;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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