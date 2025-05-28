#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    vector<int> dp1(n + 1), dp2(n + 1);
    dp1[0] = dp2[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] != -1) {
            dp1[i] = dp1[i - 1] + d[i];
            dp2[i] = dp2[i - 1] + d[i];
        } else {
            dp1[i] = dp1[i - 1];
            dp2[i] = dp2[i - 1] + 1;
        }
        dp1[i] = max(dp1[i], l[i]);
        dp2[i] = min(dp2[i], r[i]);

        if (dp1[i] > dp2[i]) {
            cout << -1 << '\n';
            return;
        }
    }

    // cout << "TODO\n";
    vector<int> h(n + 1);
    h[n] = dp1[n];
    for (int i = n; i; i--) {
        if (d[i] != -1) {
            h[i - 1] = h[i] - d[i];
        } else {
            int r0 = h[i], r1 = h[i] - 1;
            if (r0 >= dp1[i - 1] && r0 <= dp2[i - 1]) {
                d[i] = 0;
                h[i - 1] = r0;
            } else {
                d[i] = 1;
                h[i - 1] = r1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
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