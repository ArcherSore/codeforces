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

    int fin = -1, flag = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] && !flag) {
            fin = i + k - 1;
            flag = 1;
        }
        if (v[i] && i > fin) {
            cout << "NO\n";
            return;
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