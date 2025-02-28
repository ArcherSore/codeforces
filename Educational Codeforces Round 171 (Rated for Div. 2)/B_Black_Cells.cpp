#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    if ((n & 1) == 0) {
        LL res = 0;
        for (int i = 1; i < n; i += 2) {
            res = max(res, v[i] - v[i - 1]);
        }
        cout << res << '\n';
    } else {
        LL res = 1e18;
        for (int i = 0; i < n; i++) {
            LL tres = 1;
            for (int j = 1; j < n; j += 2) {
                if (j - 1 == i) {
                    tres = max(tres, v[j + 1] - v[j]);
                    j += 1;
                } else if (j == i) {
                    tres = max(tres, v[j + 1] - v[j - 1]);
                    j += 1;
                } else {
                    tres = max(tres, v[j] - v[j - 1]);
                }
            }
            res = min(res, tres);
        }
        cout << res << '\n';
    }
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