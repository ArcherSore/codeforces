#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    vector<ll> dp(n + 1);
    dp[1] = h[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + h[i] - 1, dp[i - 2] + h[i - 1] + max(0LL, h[i] - i + 1));
    }
    cout << dp[n] << '\n';
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