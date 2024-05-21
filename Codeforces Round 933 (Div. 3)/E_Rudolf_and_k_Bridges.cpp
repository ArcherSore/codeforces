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
    LL n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<LL> res;
    vector<LL> h(m), dp(m);
    for (int i = 0; i < n; i++) {
        deque<int> q;
        for (int i = 0; i < m; i++) {
            cin >> h[i];
        }
        dp[0] = 1;
        q.push_back(0);
        for (int i = 1; i < m; i++) {
            dp[i] = dp[q.front()] + h[i] + 1;
            while (q.front() < i - d) {
                q.pop_front();
            }
            while (dp[q.back()] > dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(dp[m - 1]);
    }
    LL ans = 1e18;
    for (int i = k - 1; i < n; i++) {
        LL tot = 0;
        for (int j = i - k + 1; j <= i; j++) {
            tot += res[j];
        } 
        // cout << tot << '\n';
        ans = min(ans, tot);
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