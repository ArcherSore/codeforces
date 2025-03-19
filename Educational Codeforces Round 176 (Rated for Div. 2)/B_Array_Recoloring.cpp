#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    if (k == 1) {
        int res = 0;
        res = max(res, v[0] + v[n - 1]);
        int mx = max(v[0], v[n - 1]);
        for (int i = 1; i < n - 1; i++) {
            res = max(res, mx + v[i]);
        }
        cout << res << '\n';
        return;
    }
    sort(v.begin(), v.end(), greater<>());
    LL res = 0;
    for (int i = 0; i < k + 1; i++) {
        res += v[i];
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