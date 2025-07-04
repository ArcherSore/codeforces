#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    LL y = v[0] * 2 - v[1];
    if (y < 0) {
        cout << "NO\n";
        return;
    }
    if (y % (n + 1) == 0) {
        y /= (n + 1);
    } else {
        cout << "NO\n";
        return;
    }
    LL x = v[0] - n * y;
    if (x < 0) {
        cout << "NO\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (v[i] - x * (i + 1) - y * (n - i)) {
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