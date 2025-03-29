#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = v[(i + i) % n];
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