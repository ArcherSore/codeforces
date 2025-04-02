#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    int res = n, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == v[0]) {
            cnt++;
        } else {
            res = min(res, cnt);
            cnt = 0;
        }
    }
    if (cnt) {
        res = min(res, cnt);
    }

    cout << (res == n ? -1 : res) << '\n';
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