#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n + 2), suf(n + 2);
    LL tot = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] + tot >= v) {
            pre[i] = pre[i - 1] + 1;
            tot = 0;
        } else {
            pre[i] = pre[i - 1];
            tot += a[i];
        }
    }
    tot = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] + tot >= v) {
            suf[i] = suf[i + 1] + 1;
            tot = 0;
        } else {
            suf[i] = suf[i + 1];
            tot += a[i];
        }
    }

    vector<LL> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    LL res = -1;
    if (pre[n] >= m) {
        res = 0;
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = n + 1, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (pre[i - 1] + suf[mid] >= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l == i) {
            continue;
        }
        res = max(res, sum[l - 1] - sum[i - 1]);
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