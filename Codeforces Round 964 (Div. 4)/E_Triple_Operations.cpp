#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

LL work(LL x) {
    LL r = 0;
    while (x) {
        x /= 3;
        r++;
    }
    return r;
}

void solve() {
    LL l, r;
    cin >> l >> r;

    LL res = work(l);

    LL x = work(l), y = work(r);
    // cout << x << ' ' << y << '\n';
    if (x == y) {
        res += (r - l + 1) * x;
    } else {
        for (LL i = x + 1; i <= y - 1; i++) {
            res += 2LL * pow(3, i - 1) * i;
        }
        res += (pow(3, x) - l) * x;
        res += (r - pow(3, y - 1) + 1) * y;
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