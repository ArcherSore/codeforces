#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    vector<int> l(m, n), r(m, -1);
    int p = 0;
    for (int i = 0; i < m; i++) {
        while (p < n && a[p] < b[i]) {
            p++;
        }
        if (p == n) {
            break;
        }
        l[i] = p++;
    }
    p = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (p >= 0 && a[p] < b[i]) {
            p--;
        }
        if (p == -1) {
            break;
        }
        r[i] = p--;
    }

    if (l[m - 1] != n || r[0] != -1) {
        cout << 0 << '\n';
        return;
    }

    if (m == 1) {
        cout << b[0] << '\n';
        return;
    }

    int res = INF;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            if (r[i + 1] != -1) {
                res = min(res, b[i]);
            }
        } else if (i == m - 1) {
            if (l[i - 1] != n) {
                res = min(res, b[i]);
            }
        } else {
            if (l[i - 1] < r[i + 1]) {
                res = min(res, b[i]);
            }
        }
    }
    cout << (res == INF ? -1 : res) << '\n';
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