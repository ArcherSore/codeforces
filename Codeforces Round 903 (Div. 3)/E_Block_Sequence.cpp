#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN], dp[MAXN];

void solve() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        cin >> a[i];
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i - a[i] - 1 >= 0) {
            dp[i] = min(dp[i], dp[i - a[i] - 1]);
        }
    }
    cout << dp[n] << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}