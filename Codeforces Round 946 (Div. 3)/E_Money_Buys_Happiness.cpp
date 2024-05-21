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
    LL n, x;
    cin >> n >> x;
    vector<LL> c(n), h(n);
    LL max_h = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> h[i];
        max_h += h[i];
    }
    vector<LL> dp(max_h + 1, -1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = max_h; j >= h[i]; j--) {
            if (dp[j - h[i]] - c[i] < 0) {
                continue;
            }
            dp[j] = max(dp[j], dp[j - h[i]] - c[i]);
        }
        for (int j = 0; j <= max_h; j++) {
            dp[j] += x;
        }
    }
    for (int i = max_h; i >= 0; i--) {
        if (dp[i] >= 0) {
            cout << i << '\n';
            return;
        }
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