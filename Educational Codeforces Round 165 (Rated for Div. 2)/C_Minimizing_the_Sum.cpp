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

LL cal(vector<LL> &a, int l, int r) {
    LL mn = INF;
    for (int i = l; i <= r; i++) {
        mn = min(mn, a[i]);
    }
    return mn;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<LL>> dp(n + 1, vector<LL> (k + 1, INF));
    for (int i = 0; i <= k; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            for (int len = 0; len <= i - 1 && len <= j; len++) {
                LL mn = cal(a, i - len, i);
                dp[i][j] = min(dp[i][j], dp[i - len - 1][j - len] + (len + 1) * mn);
            }
        }
    }
    LL res = INF;
    for (int i = 0; i <= k; i++) {
        res = min(res, dp[n][i]);
    }
    // cout << sum << " ";
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