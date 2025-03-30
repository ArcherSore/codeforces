#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}

int border(int x, int y, int n, int m) {
    if (x == 1 && y != 1 && y != m) {
        return 1;
    }
    if (x == n && y != 1 && y != m) {
        return 1;
    }
    if (y == 1 && x != 1 && x != n) {
        return 1;
    }
    if (y == m && x != 1 && x != n) {
        return 1;
    }
    return 0;
}

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;

    LL tot = n * m - k, cnt = 2 * (n + m - 4);
    int sum = 0;
    for (int i = 0; i < k; i++) {
        LL x, y, c;
        cin >> x >> y >> c;
        if (border(x, y, n, m)) {
            cnt--;
            sum = (sum + c) % 2;
        }
    }

    LL res = 0;
    if (cnt >= 1) {
        res = fpow(2, tot - 1);
    } else {
        if (sum == 0) {
            res = fpow(2, tot);
        } else {
            res = 0;
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