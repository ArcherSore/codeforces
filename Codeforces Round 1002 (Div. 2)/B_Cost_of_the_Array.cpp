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
    if (k == n) {
        vector<int> t;
        for (int i = 1; i < n; i += 2) {
            t.push_back(v[i]);
        }
        t.push_back(0);
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != i + 1) {
                cout << i + 1 << '\n';
                return;
            }
        }
    }

    for (int i = 1; i <= n - k + 1; i++) {
        if (v[i] != 1) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 2 << '\n';
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