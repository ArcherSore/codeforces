#include <bits/stdc++.h>
using namespace std;

set<int> s;

void init() {
    for (int i = 1; i <= 31622; i++) {
        s.insert(i);
        s.insert((i + 1) * (i + 1) - 1);
    }
}

void solve() {
    int a, l, r, res;
    cin >> a >> l >> r;
    // if (s.find(a) == s.end()) {
    //     res = (l <= a && a <= r);
    // } else {
    //     auto le = s.lower_bound(l);
    //     auto ri = s.upper_bound(r);
    //     res = distance(le, ri);
    // }
    // cout << res << '\n';
    cout << r - l + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

// 54:24 1