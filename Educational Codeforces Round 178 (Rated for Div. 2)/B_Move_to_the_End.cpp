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
    vector<LL> mx(n);
    mx[0] = v[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], v[i]);
    }

    LL sum = 0;
    for (int i = n - 1; i >= 1; i--) {
        cout << sum + mx[i] << ' ';
        sum += v[i];
    }
    cout << sum + v[0] << '\n';
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