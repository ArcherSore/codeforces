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

    int max_a = 0, max_b = 0;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        set<int> s;
        for (int j = 0, x; j < len; j++) {
            cin >> x;
            s.insert(x);
        }

        int a = -1, b = -1;
        for (int j = 0; j < len + 2; j++) {
            if (s.find(j) == s.end()) {
                if (a == -1) {
                    a = j;
                } else {
                    b = j;
                }
            }
            if (b != -1) {
                break;
            }
        }

        A[i] = a, B[i] = b;
        max_a = max(max_a, a), max_b = max(max_b, b);
    }

    vector<vector<int>> G(max_b + 1);
    vector<int> cnt(max_b + 1);
    for (int i = 0; i < n; i++) {
        G[A[i]].push_back(B[i]);
        cnt[A[i]]++;
    }

    int max_reach = max_a;
    vector<int> dp(max_b + 1);
    for (int i = max_b; i >= 0; i--) {
        dp[i] = i;
        for (auto j : G[i]) {
            dp[i] = max(dp[i], dp[j]);
        }
        if (cnt[i] > 1) {
            max_reach = max(max_reach, dp[i]);
        }
    }

    LL ans = 0;
    for (int i = 0; i <= min(m, max_b); i++) {
        ans += max(dp[i], max_reach);
    }
    if (m > max_b) {
        ans += 1LL * (max_b + 1 + m) * (m - max_b) / 2;
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