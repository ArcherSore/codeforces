#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> res(n), f;
    if (n - m * k <= k) {
        f.resize(k);
        iota(f.begin(), f.end(), 0);
        for (int i = 0; i < n; i++) {
            res[i] = f[i % k];
        }
    } else {
        int sz = n / (m + 1);
        // cout << sz << '\n';
        f.resize(sz);
        iota(f.begin(), f.end(), 0);
        for (int i = 0; i < n; i++) {
            res[i] = f[i % sz];
        }
    }
    
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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