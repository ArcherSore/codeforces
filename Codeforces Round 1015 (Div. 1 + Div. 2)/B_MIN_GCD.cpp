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
    sort(v.begin(), v.end());
    vector<LL> f;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[0]) {
            cout << "Yes\n";
            return;
        }
        if (v[i] % v[0] == 0) {
            f.push_back(v[i]);
        }
    }
    if (f.size() == 0) {
        cout << "No\n";
        return;
    }
    LL r = f[0];
    for (int i = 1; i < f.size(); i++) {
        r = gcd(r, f[i]);
    }
    if (v[0] == r) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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