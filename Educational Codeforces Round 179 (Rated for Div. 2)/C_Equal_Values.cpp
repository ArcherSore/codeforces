#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }

    LL res = 1e18;
    int lst = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] != v[lst]) {
            // [lst, i)
            res = min(res, 1LL * (lst + n - i) * v[lst]);
            lst = i;
        }
    }
    res = min(res, 1LL * lst * v[n - 1]);

    cout << (res == 1e18 ? 0 : res) << '\n';
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