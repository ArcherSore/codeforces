#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> x(n), r(n);
    for (auto &t : x) {
        cin >> t;
    }
    for (auto &t : r) {
        cin >> t;
    }

    map<LL, LL> h;
    for (int i = 0; i < n; i++) {
        for (int j = x[i] - r[i]; j <= x[i] + r[i]; j++) {
            h[j] = max(h[j], (LL)sqrt(r[i] * r[i] - (x[i] - j) * (x[i] - j)));
        }
    }

    LL res = h.size();
    for (auto [j, hi] : h) {
        res += 2 * hi;
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