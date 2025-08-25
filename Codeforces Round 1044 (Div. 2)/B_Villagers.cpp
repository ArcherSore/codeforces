#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    ll res = 0;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            res += v[i + 1];
        }
    } else {
        res = v[0];
        for (int i = 1; i < n; i += 2) {
            res += v[i + 1];
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