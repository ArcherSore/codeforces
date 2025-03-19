#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> k >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    vector<LL> sum(n);
    sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + v[i];
    }

    LL res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] >= k) {
            res += 2LL * (k - 1) * (n - i - 1);
        } else {
            // the fir p1 that v[i]+v[p1]>=k
            int p1 = lower_bound(v.begin(), v.end(), k - v[i]) - v.begin();
            p1 = max(p1, i + 1);
            // the fir p2 that v[p2]>=k
            int p2 = lower_bound(v.begin(), v.end(), k) - v.begin();
            p2 = max(p2, i + 1);

            // [p1, p2)
            if (p1 < p2) {
                res += 2LL * (v[i] + 1 - k) * (p2 - p1) + 2 * (sum[p2 - 1] - sum[p1 - 1]);
            }
            // [p2, n)
            if (p2 < n) {
                res += 2LL * v[i] * (n - p2);
            }
        }
    }

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