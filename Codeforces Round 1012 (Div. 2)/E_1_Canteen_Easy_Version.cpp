#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    vector<LL> prea(n), preb(n);
    prea[0] = a[0], preb[0] = b[0];
    for (int i = 1; i < n; i++) {
        prea[i] = prea[i - 1] + a[i];
        preb[i] = preb[i - 1] + b[i];
    }

    auto check = [&](int i, int j) -> bool {
        if (i <= j) {
            return (prea[j] - (i ? prea[i - 1] : 0)) <= (preb[j] - (i ? preb[i - 1] : 0));
        } else {
            return (prea[j] + prea[n - 1] - prea[i - 1]) <= (preb[j] + preb[n - 1] - preb[i - 1]);
        }
    };

    vector<int> d(n, -1);
    auto work = [&](auto &self, int i) -> void {
        d[i] = i;
        while (!check(i, d[i])) {
            int j = (d[i] + 1) % n;
            if (d[j] == -1) {
                self(self, j);
            }
            d[i] = d[j];
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (d[i] != -1) {
            continue;
        }
        work(work, i);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] < i) {
            res = max(res, d[i] + n - i + 1);
        } else {
            res = max(res, d[i] - i + 1);
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