#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> pre(n + 1);
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    if (*max_element(a.begin() + 1, a.end()) > b[1]) {
        cout << -1 << '\n';
        return;
    }

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int k = 1; k <= m; k++) {
        int j = 0;
        for (int i = 0; i <= n; i++) {
            while (j + 1 <= n && pre[j + 1] - pre[i] <= b[k]) {
                j++;
            }
            if (j > i) {
                dp[j] = min(dp[j], dp[i] + m - k);
            }
        }
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