#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n);
    for (auto &x : b) {
        cin >> x;
    }
    int cnt = 0;
    vector<int> res(n);
    res[0] = ++cnt;
    for (int i = 1; i < n; i++) {
        if (i - (b[i] - b[i - 1]) < 0) {
            res[i] = ++cnt;
        } else {
            res[i] = res[i - b[i] + b[i - 1]];
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