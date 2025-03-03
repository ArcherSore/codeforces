#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct Tree {
    int x, h;
};

void solve() {
    int n;
    cin >> n;
    vector<Tree> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].h;
    }
    sort(a.begin(), a.end(), [](const Tree &a, const Tree &b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.h < b.h;
    });
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<vector<int>> dp(n, vector<int> (3));
    dp[0][0] = 0, dp[0][1] = 1, dp[0][2] = (a[0].x + a[0].h < a[1].x);
    for (int i = 1; i < n; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

        if (a[i].x - a[i].h > a[i - 1].x) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
        if (a[i].x - a[i].h > a[i - 1].x + a[i - 1].h) {
            dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
        }

        if (i == n - 1) {
            dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        } else {
            if (a[i].x + a[i].h < a[i + 1].x) {
                dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
            }
        }
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}