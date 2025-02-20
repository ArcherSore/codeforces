#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

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
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++) {
        int p = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]) - b.begin();
        if (p == m) {
            if (a[i - 1] <= a[i]) {
                continue;
            }
            cout << "NO\n";
            return;
        } else {
            if (a[i - 1] <= a[i]) {
                a[i] = min(a[i], b[p] - a[i]);
            } else {
                a[i] = b[p] - a[i];
            }
        } 
    }
    cout << "YES\n";
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