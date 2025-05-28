#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    if ((a[0] + a.back()) % 2 == 0) {
        cout << 0 << '\n';
    } else {
        int res = n;
        int p = 0;
        while (p < n && (a[p] % 2) != (a.back() % 2)) {
            p++;
        }
        res = min(res, p);
        p = n - 1;
        while (p >= 0 && (a[p] % 2) != (a[0] % 2)) {
            p--;
        }
        res = min(res, n - p - 1);

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